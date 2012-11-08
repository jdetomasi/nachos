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
#include "synch.h"
#include "string.h"

Lock* lock;
Condition* condition;

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
    lock->Acquire();
    
    // Reinterpret arg "name" as a string
    char* threadName = (char*)name;
	if (strcmp ("Hilo 0", threadName) != 0)
		condition->Wait();
    lock->Release();
    currentThread->Yield();
    lock->Acquire();
    // If the lines dealing with interrupts are commented,
    // the code will behave incorrectly, because
    // printf execution may cause race conditions.
    for (int num = 0; num < 10; num++) {
        //IntStatus oldLevel = interrupt->SetLevel(IntOff);
	printf("*** thread %s looped %d times\n", threadName, num);
	//interrupt->SetLevel(oldLevel);
        currentThread->Yield();
    }
    
    
    //IntStatus oldLevel = interrupt->SetLevel(IntOff);
    printf(">>> Thread %s has finished\n", threadName);
    //interrupt->SetLevel(oldLevel);
    lock->Release();
	printf(">>> FRUTA!!!! %s \n", threadName);
	
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a ping-pong between several threads, by launching
//	ten threads which call SimpleThread, and finally calling 
//	SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest()
{
    DEBUG('t', "Entering SimpleTest");
	lock = new Lock("Testing Lock");
	condition = new Condition("Condition Var Test", lock);
	lock->Acquire();
    for ( int k=1; k<=10; k++) {
      char* threadname = new char[100];
      sprintf(threadname, "Hilo %d", k);
      Thread* newThread = new Thread (threadname);
      newThread->Fork (SimpleThread, (void*)threadname);
    }
	lock->Release();
	
    currentThread->Yield();
	currentThread->Yield();
	currentThread->Yield();
	currentThread->Yield();
	currentThread->Yield();
	currentThread->Yield();
	currentThread->Yield();
	currentThread->Yield();
	currentThread->Yield();
	
	lock->Acquire();
	condition->Broadcast();
	lock->Release();
	currentThread->Yield();
	
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>ENTROOOOOOO\n\n");
    //Thread* newThread = new Thread ("Hilo 0");
    //newThread->Fork (SimpleThread, (void *)"Hilo 0");
    SimpleThread((void *) "Hilo 0");
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SALIOOOOOOO\n\n");
	    
	
    //lock->Acquire();
    //condition->Signal();
    //lock->Release();
	
	lock->Acquire();
    lock->Release();
    //MailBoxTest();
    printf("CHAUUUUUUUUUUUUUUUUUUUUUU\n\n\n\n");
}

/*
void MailBoxTest() {
	Thread* thread1 = new Thread ("thread1");
	thread1->Fork
	Thread* thread2 = new Thread ("thread2");
	Thread* thread3 = new Thread ("thread3");
	Thread* thread4 = new Thread ("thread4");
	Thread* thread5 = new Thread ("thread5");
	thread2->Join();
	Lock* port = new Lock("port");n
	MailBox mailBox = new MailBox("mail_box", port)
	
	
}
*/
