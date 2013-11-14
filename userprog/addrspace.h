// addrspace.h 
//	Data structures to keep track of executing user programs 
//	(address spaces).
//
//	For now, we don't keep any information about address spaces.
//	The user level CPU state is saved and restored in the thread
//	executing the user program (see thread.h).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#ifndef ADDRSPACE_H
#define ADDRSPACE_H

#include "copyright.h"
#include "filesys.h"
#include "memorybitmap.h"
#include "coremap.h"
#include "noff.h"

#define UserStackSize		1024 	// increase this as necessary!

#define NEVER_LOADED    -1
#define IN_SWAP         -2

class AddrSpace {
  public:
    AddrSpace(OpenFile *executable);	// Create an address space,
					// initializing it with the program
					// stored in the file "executable"
    ~AddrSpace();			// De-allocate an address space

    void InitRegisters();		// Initialize user-level CPU registers,
					// before jumping to user code

    void SaveState();			// Save/restore address space-specific
    void RestoreState();		// info on a context switch 
    void SetArguments(int argc, int argv, char* file_name);
    void LoadArguments();
    void UpdateTLB();                   // On tlb miss, update the TLB to hold the
                                        // needed TranslationEntry
    void SaveToSwap(int vpage);
    void GetFromSwap(int vpage);

    void FreeMemory();                   // Let the memory bitmap know that we are
                                         // not using the physical pages anymore

    //bool IsDirty(int vpage); 
    bool IsUsed(int vpage); 
    void SetUsed(int vpage); 


  private:
    TranslationEntry *pageTable;	// Assume linear page table translation
					// for now!
    unsigned int numPages;		// Number of pages in the virtual 
					// address space
    MemoryBitMap* memoryBitMap;

    CoreMap* coreMap;
    void LoadPage(int virPage);
    OpenFile *swap;
    int last_modify;

    void CopyToMemory(int, int, int);
    bool isCode (int addr);     // Check if addr belongs to code segment
    bool isData (int addr);     // Check if addr belongs to initData segment
    int argc;  
    char **argv;
    OpenFile *executable;
    NoffHeader noffH;
    
};

#endif // ADDRSPACE_H
