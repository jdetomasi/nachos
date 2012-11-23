// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create several threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustrate the inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.
//
// Parts from Copyright (c) 2007-2009 Universidad de Las Palmas de Gran Canaria
//

#include "copyright.h"
#include "system.h"

//----------------------------------------------------------------------
//  FUNCTION PROTOTYPES
//----------------------------------------------------------------------
void SimpleTest();
void LockTest();
void CondVarTest();
void HandShakeTest();
    void HandShakeSend(void* puerto);
    void HandShakeReceive(void* puerto);
void MultiPriorityTest();
void PriorityInheritanceTest();
void LowFunc(void* lock);
    void MedFunc(void* tmp);
    void HighFunc (void* lock);

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 10 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"name" points to a string with a thread name, just for
//      debugging purposes.
//----------------------------------------------------------------------

void
SimpleThread(void* name)
{
    // Reinterpret arg "name" as a string
    char* threadName = (char*)name;
    
    for (int num = 0; num < 10; num++) {
	   printf("*** thread %s looped %d times\n", threadName, num);
       // Sin este cambio de contexto explicito, cada thread termina!
     currentThread->Yield();
    }

    printf(">>> Thread %s has finished\n", threadName);
}

//----------------------------------------------------------------------
// Lockinghread
//  Loop 10 times, with a lock, so no other thread can run LockingThread
//
//  "name" points to a string with a thread name, just for
//      debugging purposes.
//----------------------------------------------------------------------
void LockingThread(void* lockTest){
    const char* threadName = currentThread->getName();
    
    // Reinterpret arg "lockTest" as a lock   
    ((Lock*)lockTest)->Acquire();
    
    for (int num = 0; num < 10; num++) {
        printf("*** thread %s looped %d times\n", threadName, num);
        // No cambia nada, ya que yo poseo el lock.
        currentThread->Yield(); 
    }

    printf(">>> Thread %s has finished\n", threadName);
    ((Lock*)lockTest)->Release();
}


//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between several threads, by launching
//	ten threads which call SimpleThread, and finally calling 
//	SimpleThread ourselves.
//----------------------------------------------------------------------
void ThreadTest(){
    
//  printf("-----------------\nEntering Simple Test\n-----------------\n");SimpleTest();
//  printf("-----------------\nEntering Lock Test\n");LockTest();

//  TODO Realizar el test para las condition variables!
//  printf("-----------------\nEntering Cond Var Test\n-----------------\n");CondVarTest();
  printf("-----------------\nEntering Message Passing Test Handshake-like\n-----------------\n");HandShakeTest();
//  printf("-----------------\nEntering Multi-Priority Scheduler\n-----------------\n");MultiPriorityTest();
//  printf("-----------------\nEntering PriorityInheritance Test\n-----------------\n");PriorityInheritanceTest();

}

//----------------------------------------------------------------------
// Simple Test
//----------------------------------------------------------------------
void SimpleTest(){
    DEBUG('t', "Entering SimpleTest");

    for ( int k=1; k<=10; k++) {
      char* threadname = new char[100];
      sprintf(threadname, "Hilo %d", k);
      Thread* newThread = new Thread (threadname);
      newThread->Fork (SimpleThread, (void*)threadname);
    }
    
    SimpleThread( (void*)"Hilo 0"); 
}

//----------------------------------------------------------------------
// Test para los locks
// El thread 0 debe terminar y luego cada thread empieza y termina, 
// sin un orden en particular entre ellos.
//----------------------------------------------------------------------
void LockTest(){
    DEBUG('t', "Entering LockTest");

    // Definimos un lock, que cada thread creado intentara adquirir.
    Lock* lockTest = new Lock("Lock for Locks test");
    lockTest->Acquire();

    for ( int k=1; k<=10; k++) {
        char* threadname = new char[100];
        sprintf(threadname, "Hilo %d", k);
        Thread* newThread = new Thread (threadname);
        newThread->Fork (LockingThread, (void*)lockTest);
        // Cedo el uso del procesador, pero 
        // como tengo el lock, los demas threads no pueden continuar
        currentThread->Yield();
    }

    SimpleThread( (void*)"Hilo 0");
    lockTest->Release();
}

//----------------------------------------------------------------------
// Test para los ports
// Handshake like communication between threads.
//----------------------------------------------------------------------

struct Puertos{
    Port *puerto1, *puerto2;
    Puertos(Port *p1, Port *p2);
};

Puertos::Puertos(Port* p1, Port* p2){
    puerto1 = p1;
    puerto2 = p2;
}

void HandShakeTest(){
    DEBUG('t', "Entering HandShakeTest");

    Puertos* ports;

    for ( int k=0; k<=9; k++) {
        char* threadname = new char[100];
        sprintf(threadname, "Hilo %d", k);
        Thread* newThread = new Thread (threadname);
        if (k%2 == 0){            
            Port* tmp1 = new Port("Port 1 for HandShakeTest");
            Port* tmp2 = new Port("Port 2 for HandShakeTest");
            ports = new Puertos(tmp1, tmp2);
            newThread->Fork (HandShakeSend, (void*) ports);
        }else
            newThread->Fork (HandShakeReceive, (void*) ports);
    }

    //SimpleThread( (void*)"Hilo 0");
}

//----------------------------------------------------------------------
// Sending Threads for port Testing
//----------------------------------------------------------------------
void HandShakeSend(void* ports){
    Puertos* tmp;
    tmp = (Puertos*) ports;
    (tmp->puerto1)->Send((int)currentThread);
    int msg;
    (tmp->puerto2)->Receive(&msg);
    printf(">>>> Thread %s sent message %d\n", currentThread->getName(), (int)currentThread);
}

//----------------------------------------------------------------------
// Receiving Threads for port Testing
//----------------------------------------------------------------------
void HandShakeReceive(void* ports){
    Puertos* tmp;
    tmp = (Puertos*) ports;
    int msg;
    (tmp->puerto1)->Receive(&msg);
    Thread* threadTemp = (Thread *) msg;
    (tmp->puerto2)->Send((int)msg);
    printf("<<<< Thread %s rcvd message %d from %s\n\n", currentThread->getName(), msg, threadTemp->getName());
}

//----------------------------------------------------------------------
// Test para el scheduling con prioridades
//----------------------------------------------------------------------
void MultiPriorityTest(){
    DEBUG('t', "Entering MultiPriorityTest");

    currentThread->SetPriority(10);

    // A cada nuevo thread le asignamos mayor prioridad que los anteriores,
    // logrando que se ejecuten en orden inverso al que fueron creados.

    for ( int k=1; k<=10; k++) {
        char* threadname = new char[100];
        sprintf(threadname, "Hilo %d", k);
        Thread* newThread = new Thread (threadname);
        newThread->SetPriority(k-1);
        printf("Creado thread %d con prioridad: %d\n", k,newThread->GetPriority());
        newThread->Fork (SimpleThread, (void*)threadname);
    }

    SimpleThread( (void*)"Hilo 0");
}

//----------------------------------------------------------------------
// Test para Priority Inheritance
//----------------------------------------------------------------------
void PriorityInheritanceTest(){
    DEBUG('t', "Priority Inheritance Test");

    Lock* lock = new Lock("Priority Inheritance Lock");
    Thread* lowPriority = new Thread("Low Priority Thread");
    lowPriority->SetPriority(1);
    lowPriority->Fork(LowFunc, lock);
}

void LowFunc(void* lock){
    ((Lock*)lock)->Acquire();
    Thread* medPriority = new Thread("Medium Priority Thread");
    medPriority->SetPriority(5);
    medPriority->Fork(MedFunc, lock);
    currentThread->Yield();
    printf("Ending Low Priority Thread\n");
    ((Lock*)lock)->Release();
}

void MedFunc(void* tmp){
    Thread* higPriority = new Thread("High Priority Thread");
    higPriority->SetPriority(9);
    higPriority->Fork(HighFunc, tmp);
    currentThread->Yield();
    printf("They saw me running! They Stopped me! :( \n");
    printf("Ending Med Priority Thread\n");
}

void HighFunc (void* lock){
    ((Lock*)lock)->Acquire();
    printf("Ending High priority thread\n");
    ((Lock*)lock)->Release();
}