//----------------------------------------------------------------------
// exception_imp.cc 
//      Implementation of functionality of the syscalls
//----------------------------------------------------------------------
#include "system.h"
#include "filesys.h"
#include "synchconsole.h"
#include <map>

extern std::map<int,OpenFile*> openedFiles;

// This is used for storing a fresh OpenFileID
// We can search for the a number not in the keys of the map
// but decided for this for eficiency 
// 0 - Standard Input
// 1 - Standard Output
// 2 - Standard Error (Not Implemented) 
static int fresh_id = 3;

void halt();

int open(char *file_name);

int read(int* addr,int size, OpenFileId file_id);

int write(char *in_string, int size, OpenFileId file_id);

int close(OpenFileId file_id);

int mySeek(OpenFileId file_id, FilePosition newPos, int reference);


