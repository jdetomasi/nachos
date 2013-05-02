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

static void readHandler(void* c) { 
    SynchConsole *console = (SynchConsole *) c;
    console->ReadAvailable();
}
static void writeHandler(void* c) {  
    SynchConsole *console = (SynchConsole *) c;
    console->WriteDone();
}

SynchConsole::SynchConsole(){
    writeLock = new Lock("Synch Console Write Lock");
    readLock = new Lock("Synch Console Read Lock");
    readSemaphore = new Semaphore("read avail", 0);
    writeSemaphore = new Semaphore("write done", 0);
    console = new Console(NULL, NULL, readHandler, writeHandler, this);
}
SynchConsole::SynchConsole(const char *readFile, const char *writeFile){
    writeLock = new Lock("Synch Console Write Lock");
    readLock = new Lock("Synch Console Read Lock");
    readSemaphore = new Semaphore("read avail", 0);
    writeSemaphore = new Semaphore("write done", 0);
    console = new Console(readFile, writeFile, readHandler, writeHandler, this);

}

SynchConsole::~SynchConsole(){
    /*delete writeLock;
    delete readLock;
    delete readSemaphore;
    delete writeSemaphore;
    delete console;*/
}

void SynchConsole::ReadLine(char* data){
    readLock->Acquire();
    char c;
    while((c = console->GetChar()) != EOF){
        *data++ = c;
    }
    readSemaphore->P();
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

char SynchConsole::ReadChar(){
    readLock->Acquire();
    char c;
    readSemaphore->P();
    c = console->GetChar();
    readLock->Release();
    return c;
}

void SynchConsole::WriteChar(char ch){
    writeLock->Acquire();
    console->PutChar(ch);
    writeSemaphore->P();
    writeLock->Release();
}        

void SynchConsole::WriteDone(){
    writeSemaphore->V(); 
}

void SynchConsole::ReadAvailable(){
    readSemaphore->V(); 
}
