//----------------------------------------------------------------------
// exception_imp.h 
//      Implementation of functionality of the syscalls
//----------------------------------------------------------------------
#include "system.h"
#include "filesys.h"
#include "synchconsole.h"
#include <map>

// Modos de acceso a un archivo
// Modes that you can choose from when opening a file
enum Modes{
    O_RDONLY,
    O_WONLY,
    O_RDWR,
    O_TRUNC
};
// Structure to manage files
typedef struct filesStruct {
    OpenFile* file;
    Thread* owner;
    Modes mode;
} FileStruct;

// Structure to manage multiple processes 
typedef struct ProcessStruct {
    Thread* owner;
    int ret;
    int isJoineable;
} ProcessStruct;

// Mapping to store opened Files 
extern std::map<OpenFileId,FileStruct*> openedFiles;

// Mapping to store created Addresses
extern std::map<Pid,ProcessStruct*> processTable;

void halt();

int open(char *file_name);

int read(int* addr,int size, OpenFileId file_id);

int write(char *in_string, int size, OpenFileId file_id);

int close(OpenFileId file_id);

int mySeek(OpenFileId file_id, FilePosition newPos, int reference);

int exec(OpenFile* executable, char* file_name, int argc, int argv, int isJoineable);

int join(Pid pid);

void sexit(int ret);
