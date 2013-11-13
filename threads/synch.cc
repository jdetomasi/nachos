// synch.cc 
//	Routines for synchronizing threads.  Three kinds of
//	synchronization routines are defined here: semaphores, locks 
//   	and condition variables (the implementation of the last two
//	are left to the reader).
//
// Any implementation of a synchronization routine needs some
// primitive atomic operation.  We assume Nachos is running on
// a uniprocessor, and thus atomicity can be provided by
// turning off interrupts.  While interrupts are disabled, no
// context switch can occur, and thus the current thread is guaranteed
// to hold the CPU throughout, until interrupts are reenabled.
//
// Because some of these routines might be called with interrupts
// already disabled (Semaphore::V for one), instead of turning
// on interrupts at the end of the atomic operation, we always simply
// re-set the interrupt state back to its original value (whether
// that be disabled or enabled).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synch.h"
#include "system.h"

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(const char* debugName, int initialValue)
{
    name = debugName;
    value = initialValue;
    queue = new List<Thread*>;
}

//----------------------------------------------------------------------
// Semaphore::~Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore()
{
    delete [] queue;
}

//----------------------------------------------------------------------
// Semaphore::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

void
Semaphore::P()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts
    
    while (value == 0) { 			// semaphore not available
	queue->Append(currentThread);		// so go to sleep
        DEBUG('l', "Sleeping thread %s 'cause of semaphore %s\n", currentThread->getName(), this->getName());
        DEBUG('e', "Sleeping thread %s 'cause of semaphore %s\n", currentThread->getName(), this->getName());
	currentThread->Sleep();
        //DEBUG('l', "Sleeping thread \"%s\"\n", currentThread->getName());
    } 
    value--; 					// semaphore available, 
						// consume its value
    
    interrupt->SetLevel(oldLevel);		// re-enable interrupts
}

//----------------------------------------------------------------------
// Semaphore::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that threads
//	are disabled when it is called.
//----------------------------------------------------------------------

void
Semaphore::V()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);
    Thread *thread;

    thread = queue->Remove();
    if (thread != NULL){	   // make thread ready, consuming the V immediately
	scheduler->ReadyToRun(thread);
    }
    value++;
    interrupt->SetLevel(oldLevel);
}

//----------------------------------------------------------------------
// Lock::Lock
//  Initialize a lock for avoiding interference in critical sections
//
//  "debugName" is an arbitrary name, useful for debugging.
//----------------------------------------------------------------------
Lock::Lock(const char* debugName) 
{  
    name = debugName;
    holderThread = NULL;
    lockSem = new Semaphore("Semaphore from Lock", 1);
}

//----------------------------------------------------------------------
// Lock::~Lock
//  De-allocate a lock, when no longer needed.  Assume no one
//  is still using it.
//----------------------------------------------------------------------
Lock::~Lock(){
    delete lockSem;
}

//----------------------------------------------------------------------
// Lock::Acquire
//  Ask for the exclusive use of the lock. If idle, gets it, if not
//  the thread go to sleep.
//----------------------------------------------------------------------
void Lock::Acquire() {
    
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts
    // Arrgh! - Thread already owns the lock!
    ASSERT(!isHeldByCurrentThread());

    // If the lock is already held by other thread with lower priority, sets 
    // the holderThread priority to be equal to the one trying to get the lock.
    if (holderThread != NULL){
        if (holderThread->GetPriority() < currentThread->GetPriority()){
            oldPriority = holderThread->GetPriority();
            holderThread->SetPriority(currentThread->GetPriority());
        }

    }
    // If the lock is free, takes the lock, else it waits for it to be freed.
    lockSem->P();				
    
    // Sets the holder to be the current thread and saves its priority.
    ASSERT(holderThread == NULL);
    holderThread = currentThread;
    DEBUG('l', "Thread %s acquired lock %s\n", holderThread->getName(), this->getName());
    oldPriority = currentThread->GetPriority();
    interrupt->SetLevel(oldLevel);		// re-enable interrupts
}

//----------------------------------------------------------------------
// Lock::Realease
//  Releases the lock that must be held by the caller thread.
//----------------------------------------------------------------------
void Lock::Release() {
    
    // Arrgh! - Thread not in possesion of the lock and doing a Release()!
    ASSERT(isHeldByCurrentThread());
    
    // First we have to set the holder to NULL, otherwise if a change 
    // of context occurs before doing so and having realeased the lock, 
    // another thread gets it and it gets erased when this one resumes.
    DEBUG('l', "Thread %s realeased lock %s\n", holderThread->getName(), this->getName());
    holderThread = NULL;
    
    // The lock is freed.
    lockSem->V();
    
    // Sets priority to the old level (if any).
    currentThread->SetPriority(oldPriority);
}

bool Lock::isHeldByCurrentThread() {
    return(currentThread == holderThread);
}

//----------------------------------------------------------------------
// Condition::Condition
//  Initialize a condition variable, sets the lock that will control the
//  use of it.
//----------------------------------------------------------------------
Condition::Condition(const char* debugName, Lock* condLock) { 
    name = debugName;
    this->conditionLock = condLock;
    waitingList = new List<Semaphore*>;
}

//----------------------------------------------------------------------
// Condition::~Condition
//  De-allocate condition variable. Assumes no one is waiting for it.
//----------------------------------------------------------------------
Condition::~Condition() {
    delete conditionLock;
    delete [] waitingList;
 }

//----------------------------------------------------------------------
// Condition::Wait
//  Waits for a certain condition to be signaled. It creates a new 
//  semaphore for every thread waiting. Assumes you have the lock.
//----------------------------------------------------------------------
void Condition::Wait() { 
    
    // Checks wheter the thread owns the lock.
    ASSERT(conditionLock->isHeldByCurrentThread());

    // Initially zero in order to make the thread wait for a signal
    Semaphore *tmpSem = new Semaphore("Temporary Semaphore for Cond Var", 0); 
    waitingList->Append(tmpSem);
    conditionLock->Release();
    
    // Since it is created with zero-value, the thread will go to sleep!
    tmpSem->P();			
    
    // Re-adquire the condition variable lock!						
    conditionLock->Acquire();
    delete tmpSem;
}

//----------------------------------------------------------------------
// Condition::Signal
//  Sends a signal for current condition variable. If someone is waiting
//  for it, it is waked up, otherwise the signal get lost.
//----------------------------------------------------------------------
void Condition::Signal() { 

    // Checks wheter the thread owns the lock.
    ASSERT(conditionLock->isHeldByCurrentThread());

    if (!waitingList->IsEmpty())
      (waitingList->Remove())->V();
}

//----------------------------------------------------------------------
// Condition::Broadcast
//  Sends a signal for current condition variable. 
//  It wakes up all waiting threads.
//----------------------------------------------------------------------
void Condition::Broadcast() { 

    // Checks wheter the thread owns the lock.
    ASSERT(conditionLock->isHeldByCurrentThread());	

    while (!waitingList->IsEmpty())
      (waitingList->Remove())->V();    
}

//----------------------------------------------------------------------
// Port::Port
//  Initialize a port used for communication.
//----------------------------------------------------------------------
Port::Port(const char* debugName){
    name = debugName;
    portLock = new Lock("Condition variable lock");
    mailRcv = new Condition("Cond of Receiver", portLock);
    mailSnd = new Condition("Cond of Sender", portLock);
	isBusy = 0;
	message = 0;
}

//----------------------------------------------------------------------
// Port::~Port
//  De-allocate a port.
//----------------------------------------------------------------------
Port::~Port(){
    delete mailRcv;
    delete mailSnd;
};

void Port::Send(int msg){
    portLock->Acquire();
    
    // Wait until the port is not busy
    while (isBusy == 1) mailRcv->Wait();  

    // Copy the sended message
    message = msg;
    
    // Set the port status to BUSY
    isBusy = 1;							 

    // Notify the waiting thread (if any) that a message has been sent
    mailSnd->Signal();				 	 

	ASSERT(portLock->isHeldByCurrentThread());
    portLock->Release();					 
}

void Port:: Receive(int *msg) {
    portLock->Acquire();

    // If no messages wait until a message arrives
	while (isBusy == 0) mailSnd->Wait(); 

    *msg = message;

    // Set the port status to ~BUSY
    isBusy = 0;

    // Notify that the message has been recieved
    mailRcv->Signal();
    
    ASSERT(portLock->isHeldByCurrentThread());
    
    portLock->Release();
}
