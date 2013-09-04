//----------------------------------------------------------------------
// coremap.h 
//      Definition of a singleton pattern like coremap, to manage all
//      memory of the processes
//----------------------------------------------------------------------

#include "memorybitmap.h"
#include "machine.h"
#include "list.h"

#ifndef COREMAP_H
#define COREMAP_H
class Thread;

class MemoryStatus {
  public:
      int virtPage;
      Thread* owner;
};

class CoreMap{
private:
    static CoreMap *single;
    CoreMap(int nitems);
    ~CoreMap();
    MemoryBitMap *memoryBitMap;
    MemoryStatus *memoryStatus;

public:
    static CoreMap* GetInstance();
    int Find(int virtPage);
    bool Check(int virtPage, int physPage);
    int GetSwapCandidate();
};

#endif //COREMAP_H
