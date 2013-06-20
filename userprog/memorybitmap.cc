//----------------------------------------------------------------------
// memory_bitmap.cc 
//      Implementation of a singleton GetInstance method
//      If no instance, create one, else return instance
//----------------------------------------------------------------------

#include "memorybitmap.h"
#include "machine.h"
MemoryBitMap* MemoryBitMap::single = NULL;

MemoryBitMap* MemoryBitMap::GetInstance(){
    if(single == NULL){
        single = new MemoryBitMap(NumPhysPages);
        return single;
    } else
        return single;
   
}

MemoryBitMap::MemoryBitMap(int nitems)
    :BitMap(nitems)
{
        // Empty Constructor
}
