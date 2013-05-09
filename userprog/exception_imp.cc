//----------------------------------------------------------------------
// exception_imp.cc 
//      Implementation of functionality of the syscalls
//----------------------------------------------------------------------
#include "system.h"
#include "synchconsole.h"
#include "filesys.h"
#include "syscall.h"
#include "syscall_utils.h"
#include <map>

std::map<int,OpenFile*> openedFiles;
//std::map<int,AddrSpace*> currentSpaces;

// This is used for storing a fresh AddrSpaceID
// We can search for the a number not in the keys of the map
// but decided for this for eficiency 
// 0 - Standard Input
// 1 - Standard Output
// 2 - Standard Error (Not Implemented) 
//static int fresh_id = 3;

// This is used for storing a fresh OpenFileID
// We can search for the a number not in the keys of the map
// but decided for this for eficiency 
// 0 - Standard Input
// 1 - Standard Output
// 2 - Standard Error (Not Implemented) 
static int fresh_id = 3;

void halt(){
    interrupt->Halt();
}

int open(char *file_name){

    OpenFile* file_id; 
    file_id = fileSystem->Open(file_name);
    if  (!file_id){
        return -1;
    }

    openedFiles.insert(
        std::pair<int,OpenFile*>(fresh_id, file_id));

    return fresh_id++;
}

int read(int* addr,int size, OpenFileId file_id){
     
    int num_read;
    char chars_read[100];
    if (file_id == ConsoleInput){
        SynchConsole *console = new SynchConsole();
        char ch;
        int i;
        i = 0;
        while (size >= 1){
            //chars_read = console->ReadChar();
            writeString(*addr, chars_read, 1); 
        }
        delete console;
        return 0;
    }
    if (openedFiles.find(file_id) ==  openedFiles.end() || file_id == ConsoleOutput){
        return -1;
    }

    num_read = openedFiles[file_id]->Read(chars_read,size);
    writeString(*addr, chars_read, num_read);
    chars_read[num_read] = '\0';
    return num_read;
}

int write(char *in_string, int size, OpenFileId file_id){

    if (file_id == ConsoleOutput){
        SynchConsole *console = new SynchConsole();
        // TODO escribir solo size caracteres, no hasta \0
        console->WriteLine(in_string);
        delete console;
        return 0;
    }

    if (openedFiles.find(file_id) ==  openedFiles.end() || file_id == ConsoleInput){
        return -1;
    }
    openedFiles[file_id]->Write(in_string,size);
    return 0;
}

int close(OpenFileId file_id){

    if (openedFiles.find(file_id) ==  openedFiles.end()){
        return -1;
    }
    delete openedFiles[file_id];
    openedFiles.erase(file_id);
    return 0;
}

int mySeek(OpenFileId file_id, FilePosition newPos, int reference){

    if (openedFiles.find(file_id) ==  openedFiles.end()){
        return -1;
    }
    int ret; ret = -1;
    int file_len;
    file_len = openedFiles[file_id]->Length();
    if (reference == 0 && newPos >= 0){
        if (newPos <= file_len)
            ret = openedFiles[file_id]->SetCurrentPosition(newPos);
        else
            ret = openedFiles[file_id]->SetCurrentPosition(file_len);

    } else{
        if (reference == 1 && newPos >= 0){
            if (file_len >= newPos) 
                ret = openedFiles[file_id]->SetCurrentPosition(file_len - newPos);
            else
                ret = openedFiles[file_id]->SetCurrentPosition(0);
        } else {
                if (reference == 2){
                    int file_offset;
                    file_offset = openedFiles[file_id]->GetCurrentPosition() + newPos;
                    if (file_offset <= file_len && file_offset >= 0)
                        ret = openedFiles[file_id]->SetCurrentPosition(file_offset);
                } else 
                    ret = openedFiles[file_id]->SetCurrentPosition(file_len);
        }
    }
    return ret;

}

void startNewProcess(void* x){
    currentThread->space->InitRegisters();
    currentThread->space->RestoreState();
    machine->Run();
    ASSERT(false);
}

int exec(OpenFile* executable){
    AddrSpace *newAddrSpace;
    newAddrSpace = new AddrSpace(executable);
    delete executable;
    Thread *newThread;
    newThread = new Thread(NULL);
    newThread->space = newAddrSpace;
    newThread->Fork(startNewProcess, NULL);
    return 0;
}
