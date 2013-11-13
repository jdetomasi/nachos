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

typedef struct node{
    struct node* next;
    struct node* last;
    int physPage;
}Node;

class MemoryStatus {
  public:
      int virtPage;
      Thread* owner;
      MemoryStatus(){
          virtPage = -1;
          owner = NULL;
    };
};

class CoreMap{
private:
    static CoreMap *single;
    CoreMap(int nitems);
    ~CoreMap();
    MemoryBitMap *memoryBitMap;
    MemoryStatus *memoryStatus;
    Node *order;

public:
    static CoreMap* GetInstance();
    int Find(int virtPage);
    bool Check(int virtPage, int physPage);
    int GetPage();
    void SetPage(int page);
    int GetPidOwner(int physPage);
};
#endif //COREMAP_H
