// synchconsole.cc 
//	Routines to synchronously access the console.  The console 
//	is an asynchronous device (write and reads requests return immediately, and
//	an interrupt happens later on). This is a layer on top of
//	the console providing a synchronous interface (requests wait until
//	the request completes).
//
//	Use a semaphore to synchronize the interrupt handlers with the
//	pending requests. And, because the console can only
//	handle one operation at a time, use a lock to enforce mutual
//	exclusion.
//

#include "synchconsole.h"
// Just to be abble to use currentThread when debuging
#include "system.h"

// Pointer to the unique instance of the synchconsole
SynchConsole* SynchConsole::single = NULL;

static void readHandler(void* c) { 
    ((SynchConsole *) c)->ReadAvailable();
}
static void writeHandler(void* c) {  
    ((SynchConsole *) c)->WriteDone();
}

SynchConsole::SynchConsole(){
    writeLock = new Lock("Synch Console Write Lock");
    readLock = new Lock("Synch Console Read Lock");
    readSemaphore = new Semaphore("read avail", 0);
    writeSemaphore = new Semaphore("write done", 0);
    console = new Console(NULL, NULL, readHandler, writeHandler, this);
    DEBUG('c',"SynchConsole Created by %s to read/write\n", currentThread->getName());
}

SynchConsole* SynchConsole::GetInstance(){
    if(single == NULL){
        single = new SynchConsole();
        return single;
    } else
        return single;
}

SynchConsole::~SynchConsole(){
    delete writeLock;
    delete readLock;
    delete readSemaphore;
    delete writeSemaphore;
    delete console;
}

void SynchConsole::ReadLine(char* data){
    readLock->Acquire();
    char c;
    while((c = console->GetChar()) != EOF){
        readSemaphore->P();
        *data++ = c;
    }
    readLock->Release();
}

void SynchConsole::WriteLine(char* data){
    writeLock->Acquire();
    while(*data != '\0'){
        console->PutChar(data[0]);
        data++;
        writeSemaphore->P();
    }
    writeLock->Release();
}

const char SynchConsole::ReadChar(){
    readLock->Acquire();
    char ch;
    readSemaphore->P();
    ch = console->GetChar();
    DEBUG('c'," %s readed from SynchConsole -> %c \n", currentThread->getName(), ch);
    readLock->Release();
    return ch;
}

void SynchConsole::WriteChar(char ch){
    writeLock->Acquire();
    console->PutChar(ch);
    DEBUG('c',"%s writted to SynchConsole ->  %c \n", currentThread->getName(), ch);
    writeSemaphore->P();
    writeLock->Release();
}        

void SynchConsole::WriteDone(){
    writeSemaphore->V(); 
}

void SynchConsole::ReadAvailable(){
    readSemaphore->V(); 
}
