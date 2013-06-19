// synchconsole.h 
// 	Data structures to a synchronous console 
//

#ifndef SYNCHCONSOLE_H
#define SYNCHCONSOLE_H

#include "synch.h"
#include "console.h"



class SynchConsole {
    public:
        SynchConsole();                                              // Initialize a synchronous console that reads
                                                                     // and writes from/to the stdin/stdout
        SynchConsole(const char *readFile, const char *writeFile);   // Initialize a synchronous console that reads
                                                                     // from file readFile and writes to file writeFile
        ~SynchConsole();                                             // De-allocate console

        // Method that will be called when there is something to read
        void ReadAvailable();
        // Method that will be called when we finish writing 
        void WriteDone();
        void ReadLine(char* data);
        void WriteLine(char* data);
        void WriteChar(char ch); // Write "ch" to the console display, 
				 // and return immediately 

        const char ReadChar();	 // Poll the console input.  If a char is 
				 // available, return it.  Otherwise, return EOF.
        
    private:
        // Data structures needed for the console test. Threads making
        // I/O requests wait on a Semaphore to delay until the I/O completes.
        Semaphore *readSemaphore;
        Semaphore *writeSemaphore;
        Lock *writeLock;                         // Only one thread can write to the console at a time
        Lock *readLock;                         // Only one thread can read from the console at a time
        Console *console;                   // The actual Console

        // ConsoleInterruptHandlers
        // 	Wake up the thread that requested the I/O.

        // void ReadAvailable(void* arg) { (int *) arg == 0 ? readSemaphore->V():continue; }
        // void WriteDone(void* arg) {  (int *) arg == 0 ? writeSemaphore->V():continue; }
};
#endif

