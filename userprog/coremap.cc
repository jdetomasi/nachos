//----------------------------------------------------------------------
// coremap.cc 
//      Implementation of a singleton GetInstance method
//      If no instance, create one, else return instance
//----------------------------------------------------------------------

#include "memorybitmap.h"
#include "coremap.h"
#include "machine.h"
#include "system.h"
#include "list.h"

CoreMap* CoreMap::single = NULL;

CoreMap* CoreMap::GetInstance(){
    if(single == NULL){
        single = new CoreMap(NumPhysPages);
        return single;
    } else
        return single;
   
}

CoreMap::CoreMap(int nitems)
{
    memoryStatus = new MemoryStatus[nitems];
    memoryBitMap = MemoryBitMap::GetInstance();
}

int CoreMap::Find(int virtPage){
    // Search for a physical page to put virtual page virtPage of currentThread
    int ret = memoryBitMap->Find();
    if (ret == -1){
        // There is no more space in memory, take one out, and put it into a file
        //ret = GetSwapCandidate();
        ret = 7;
        ASSERT(memoryStatus[ret].owner);
        DEBUG('m', "Memory is full, assign virtPage %d of thread %s 
                to swap file",ret,memoryStatus[ret].owner->getName());
        int swapPage = memoryStatus[ret].virtPage;
        memoryStatus[ret].owner->space->SaveToSwap(swapPage);
        memoryStatus[ret].owner = currentThread;
        memoryStatus[ret].virtPage = virtPage;
    } else { 
        memoryStatus[ret].virtPage = ret;
        memoryStatus[ret].owner = currentThread;
    } 
    return ret;
}

bool CoreMap::Check(int virtPage, int physPage){
    return (memoryStatus[physPage].virtPage == virtPage
            && memoryStatus[physPage].owner == currentThread);
}

int CoreMap::GetSwapCandidate(){
}
