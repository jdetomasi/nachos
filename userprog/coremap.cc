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
    order = NULL;
}

int CoreMap::Find(int virtPage){
    // Search for a physical page to put virtual page virtPage of currentThread
    int ret = memoryBitMap->Find();
    if (ret == -1){
        // There is no more space in memory, take one out, and put it into a file
        ret = GetPage();
        ASSERT(NULL != memoryStatus[ret].owner);
        DEBUG('f', "Memory is full, assign virtPage %d of thread %s\
 to swap file\n",(memoryStatus[ret].virtPage),(memoryStatus[ret].owner)->getName());
        int swapPage = memoryStatus[ret].virtPage;
        memoryStatus[ret].owner->space->SaveToSwap(swapPage);
        DEBUG('f', "VirtPage %d of thread %s can use physPage %d\n",
                virtPage,currentThread->getName(),ret);
    } 
    SetPage(ret);
    memoryStatus[ret].virtPage = virtPage;
    memoryStatus[ret].owner = currentThread;
    return ret;
}

int CoreMap::GetPidOwner(int physpage){
    ASSERT(NULL != memoryStatus[physpage].owner);
    return  memoryStatus[physpage].owner->GetPid();
}

bool CoreMap::Check(int virtPage, int physPage){
    return (memoryStatus[physPage].virtPage == virtPage
            && memoryStatus[physPage].owner == currentThread
            && physPage >= 0);
}

#ifdef USE_FIFO

int CoreMap::GetPage(){
    ASSERT(order != NULL);
    int ret;
    ret = order->physPage;
    if (order->next != NULL){
        order->next->last = order->last;
        order = order->next;
    }else{
        order = NULL;
    }
    
    return ret;
}

void CoreMap::SetPage(int physPage){
    if (NULL == order){
        order = new Node();
        order->physPage = physPage;
        order->last = order;
        order->next = NULL;
    } else {
        Node* tmp = new Node();
        tmp->physPage = physPage;
        tmp->next = NULL;
        order->last->next = tmp;
        order->last = tmp;
    }
}

#else

int CoreMap::GetPage(){
    ASSERT(order != NULL);
    int ret;
    ret = order->physPage;
    int vpage;
    vpage = memoryStatus[ret].virtPage;
    ASSERT(NULL != memoryStatus[ret].owner);
    while (memoryStatus[ret].owner->space->IsUsed(vpage)){
        memoryStatus[ret].owner->space->SetUsed(vpage);
        SetPage(ret);
        ret = order->next->physPage;
    }

    if (order->next != NULL){
        order->next->last = order->last;
        order = order->next;
    }else{
        order = NULL;
    }
    
    return ret;
}

void CoreMap::SetPage(int physPage){
    if (NULL == order){
        order = new Node();
        order->physPage = physPage;
        order->last = order;
        order->next = NULL;
    } else {
        Node* tmp = new Node();
        tmp->physPage = physPage;
        tmp->next = NULL;
        order->last->next = tmp;
        order->last = tmp;
    }
}
#endif
