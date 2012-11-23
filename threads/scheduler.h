// scheduler.h 
//	Data structures for the thread dispatcher and scheduler.
//	Primarily, the list of threads that are ready to run.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef SCHEDULER_H
#define SCHEDULER_H

#define NUM_PRIORITY_LEVELS 11

#include "copyright.h"
#include "list.h"
#include "thread.h"

// The following class defines the scheduler/dispatcher abstraction -- 
// the data structures and operations needed to keep track of which 
// thread is running, and which threads are ready but not running.

class Scheduler {
  public:
    Scheduler();			// Initialize multyqueue of ready threads 
    ~Scheduler();			// De-allocate ready queues

    void ReadyToRun(Thread* thread);	// Thread can be dispatched.
    // Dequeue first thread (priority like) on the ready queues, if any, and return thread.
    Thread* FindNextToRun();
    // Changes the priority of a thread
    void UpdatePriority(Thread* thread, int oldPriority, int newPriority);
    // Cause nextThread to start running
    void Run(Thread* nextThread);
    // Print contents of all ready queues
    void Print();
    
  private:
    // Multiple queues of threads (depending on priority) that are ready to run, but not running
    List<Thread*> *readyList[NUM_PRIORITY_LEVELS];  
};

#endif // SCHEDULER_H