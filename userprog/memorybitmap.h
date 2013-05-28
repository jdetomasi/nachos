//----------------------------------------------------------------------
// memory_bitmap.h 
//      Definition of a singleton pattern like bitmap, to manage all
//      Physicall Pages of the machine memory
//----------------------------------------------------------------------

#include "bitmap.h"
#include "machine.h"

#ifndef MEMORYBITMAP_H
#define MEMORYBITMAP_H

class MemoryBitMap : public BitMap{
private:
    static MemoryBitMap *single;
    MemoryBitMap(int nitems);
    ~MemoryBitMap();

public:
    static MemoryBitMap* getInstance();
};
#endif // MEMORYBITMAP_H
