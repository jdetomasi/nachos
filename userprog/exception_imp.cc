//----------------------------------------------------------------------
// exception_imp.cc 
//      Implementation of functionality of the syscalls
//----------------------------------------------------------------------
#include "system.h"
#include "synchconsole.h"
#include "filesys.h"
#include "syscall.h"
#include "../threads/synch.h"
#include "syscall_utils.h"
#include "exception_imp.h"
#include <map>

// Mapping to store opened Files 
std::map<OpenFileId,FileStruct*> openedFiles;
// This is used for storing a fresh OpenFileID
// We can search for the a number not in the keys of the map
// but decided for this for eficiency 
// 0 - Standard Input
// 1 - Standard Output
// 2 - Standard Error (Not Implemented) 
static OpenFileId fresh_id = 3;

// Mapping to store created Addresses
std::map<Pid,ProcessStruct*> processTable;
// This is used for storing a fresh AddrSpaceID
// We can search for the a number not in the keys of the map
// but decided for this for eficiency 
static int freshPid = 1;

void halt(){
    interrupt->Halt();
}

int open(char *file_name){

    FileStruct* file_str;
    file_str = new FileStruct();
    (file_str->file) = fileSystem->Open(file_name);
    if  (!(file_str->file)){
        return -1;
    }
    file_str->owner = currentThread;
    // TODO Implementamos esto? Si lo hacemos..como?
    file_str->mode = O_RDWR;

    openedFiles.insert(
        std::pair<OpenFileId,FileStruct*>(fresh_id, file_str));

    return fresh_id++;
}

int read(int* addr,int size, OpenFileId file_id){
     
    int num_read = 0;
    char* chars_read = new char[size + 1];
    if (file_id == ConsoleInput){
        SynchConsole *console = SynchConsole::GetInstance();
        while (size > 0){
            if ((chars_read[num_read++] = 
                        console->ReadChar()) == EOF){
                break;
            }
            size = size - 1;
        }
        chars_read[num_read] = '\0';
        writeString(*addr, chars_read, num_read); 
        delete [] chars_read;
        return size;
    }
    if (openedFiles.find(file_id) ==  openedFiles.end() || file_id == ConsoleOutput){
        // The file does not exist or is not opened yet
        return -1;
    }
    if (openedFiles[file_id]->owner != currentThread){
        // The file is open but by other thread
        // TODO si agregamos los modos, hacerlo aca
        return -1;
    }
    num_read = openedFiles[file_id]->file->Read(chars_read,size);
    if (num_read > 0){
        writeString(*addr, chars_read, num_read);
    }
    delete [] chars_read;
    return num_read;
}

int write(char *in_string, int size, OpenFileId file_id){

    if (file_id == ConsoleOutput){
        SynchConsole *console = SynchConsole::GetInstance();
        while (in_string != '\0' and size-- >0)
            console->WriteChar(*in_string++);
        return 0;
    }

    if (openedFiles.find(file_id) ==  openedFiles.end() || file_id == ConsoleInput){
        // The file does not exist or is not opened yet
        return -1;
    }
    if (openedFiles[file_id]->owner != currentThread){
        // The file is open but by other thread
        // TODO si agregamos los modos, hacerlo aca
        return -1;
    }

    openedFiles[file_id]->file->Write(in_string,size);
    return 0;
}

int close(OpenFileId file_id){

    if (openedFiles.find(file_id) ==  openedFiles.end()){
        return -1;
    }
    delete openedFiles[file_id];
    openedFiles.erase(file_id);
    // TODO Como manejamos la fresh_id ? Este file_id deberia "quedar" libre...que hacemos?
    return 0;
}

int mySeek(OpenFileId file_id, FilePosition newPos, int reference){

    if (openedFiles.find(file_id) ==  openedFiles.end()){
        // The file does not exist or is not opened yet
        return -1;
    }
    if (openedFiles[file_id]->owner != currentThread){
        // The file is open but by other thread
        // TODO si agregamos los modos, hacerlo aca
        return -1;
    }
    int ret; ret = -1;
    int file_len;
    file_len = (openedFiles[file_id]->file)->Length();
    if (reference == 0 && newPos >= 0){
        if (newPos <= file_len)
            ret = (openedFiles[file_id]->file)->SetCurrentPosition(newPos);
        else
            ret = (openedFiles[file_id]->file)->SetCurrentPosition(file_len);

    } else{
        if (reference == 1 && newPos >= 0){
            if (file_len >= newPos) 
                ret = (openedFiles[file_id]->file)->SetCurrentPosition(file_len - newPos);
            else
                ret = (openedFiles[file_id]->file)->SetCurrentPosition(0);
        } else {
                if (reference == 2){
                    int file_offset;
                    file_offset = (openedFiles[file_id]->file)->GetCurrentPosition() + newPos;
                    if (file_offset <= file_len && file_offset >= 0){
                        ret = (openedFiles[file_id]->file)->SetCurrentPosition(file_offset);
                    }
                } else 
                    ret = (openedFiles[file_id]->file)->SetCurrentPosition(file_len);
        }
    }
    return ret;

}

void startNewProcess(void* x){
    currentThread->space->InitRegisters();
    currentThread->space->LoadArguments();
    currentThread->space->RestoreState();
    machine->Run();
    ASSERT(false);
}

int exec(OpenFile* executable, char* file_name, int argc, int argv, int isJoineable){
    Thread *newThread;
    if (isJoineable > 0){
        newThread = new Thread(file_name, isJoineable);
    } else{
        newThread = new Thread(file_name);
    }
    newThread->SetPid(freshPid);
    AddrSpace *newAddrSpace;
    newAddrSpace = new AddrSpace(executable);

    newAddrSpace->SetArguments(argc, argv, file_name);
    newThread->space = newAddrSpace;
    newThread->Fork(startNewProcess, NULL);
    /*
       If thread is not going to be joined, is unnecesary to create this
       data structure.
       Moreover, if the thread is created as joineable but it is never joined,
       we will have memory leaks. 
       Can we create a pointer to the caller in the structure and delete all structs
       if the thread dies?
    */
    if (isJoineable > 0){
        ProcessStruct *processStruct;
        processStruct = new ProcessStruct();
        processStruct->owner = newThread;
        processTable.insert(
            std::pair<Pid,ProcessStruct*>(freshPid, processStruct));
    }
    return freshPid++;
}

int join(Pid pid){
    if (processTable.find(pid) ==  processTable.end()){
        // Pid does not exist
        return -1;
    }
    // Wait until the thread is done
    processTable[pid]->owner->Join();
    int ret;
    ret =  processTable[pid]->ret; 
    delete processTable[pid];
    processTable.erase(pid);
    return ret;
}



void sexit(int ret){
    // Search for processTable to find the one belonging to us (if any)
    int pid;
    pid = currentThread->GetPid();
    if (processTable.find(pid) !=  processTable.end()){
        // Pid exist
        processTable[pid]->ret = ret;
    }
    currentThread->space->FreeMemory();
    delete currentThread->space;
    currentThread->space = NULL;
    currentThread->Finish(); 
    ASSERT(false);
}


