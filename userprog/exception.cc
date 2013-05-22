// exception.cc 
//    Entry point into the Nachos kernel from user programs.
//    There are two kinds of things that can cause control to
//    transfer back to here from user code:
//
//    syscall -- The user code explicitly requests to call a procedure
//    in the Nachos kernel.  Right now, the only function we support is
//    "Halt".
//
//    exceptions -- The user code does something that the CPU can't handle.
//    For instance, accessing memory that doesn't exist, arithmetic errors,
//    etc.  
//
//    Interrupts (which can also cause control to transfer from user
//    code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"
#include "syscall_utils.h"
#include "exception_imp.h"
#include "addrspace.h"

//----------------------------------------------------------------------
// ExceptionHandler
//     Entry point into the Nachos kernel.  Called when a user program
//    is executing, and either does a syscall, or generates an addressing
//    or arithmetic exception.
//
//     For system calls, the following is the calling convention:
//
//     system call code -- r2
//        arg1 -- r4
//        arg2 -- r5
//        arg3 -- r6
//        arg4 -- r7
//
//    The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//    "which" is the kind of exception.  The list of possible exceptions 
//    are in machine.h.
//----------------------------------------------------------------------

void
ExceptionHandler(ExceptionType which){

    ASSERT(interrupt->getStatus() == SystemMode);
    int last_open; last_open = 0;
    int type = machine->ReadRegister(2);
    int arg1,arg2,arg3;
    int syscall_has_fail; syscall_has_fail = 0;
    char file_name[100];
    int ret;
    Thread *newThread;
    AddrSpace *newAddrSpace;
    AddrSpace *oldAddrSpace;

    if (which == SyscallException) {
        switch(type){
            case SC_Halt:
                DEBUG('s', "System Call: %s Invoking Halt.\n",currentThread->getName());
                halt(); 
                break;
            case SC_Exit:
                DEBUG('s', "System Call: %s Invoking Exit.\n",currentThread->getName());
                machine->WriteRegister(2, machine->ReadRegister(4));
                printf("Exception Handler: %s  Exit with value %d\n", currentThread->getName(),machine->ReadRegister(4));
                currentThread->Finish();
                //      deallocate physical memory. It is sufficient with next line?
                //      Ver como pasar la info de return a un eventual thread que haga join sobre el que hace exit
                delete currentThread;
                break;
            case SC_Exec:
                DEBUG('s', "System Call: %s Invoking Exec.\n",currentThread->getName());
                printf("Exception Handler: %s  Exec\n",currentThread->getName());
                // arg1 :: char * the name of the file that stores the executable .
                arg1 = machine->ReadRegister(4);
                readString(arg1, file_name);
                ret = exec(fileSystem->Open(file_name));
                if(ret == -1){
                    syscall_has_fail = 1;
                    break;
                }
                machine->WriteRegister(2, ret);
                break;
            case SC_Join:
                DEBUG('s', "System Call: %s Invoking Join.\n",currentThread->getName());
                printf("Exception Handler: %s  Join\n",currentThread->getName());
                // arg1 :: SpaceId of the user program to join to.
                arg1 = machine->ReadRegister(4);
                oldAddrSpace = currentThread->space;
                newThread = new Thread("JoinThread");
                newThread->space = currentSpaces[last_space];
                oldAddrSpace->SaveState();
                newAddrSpace->InitRegisters();
                machine->Run();
                newThread->Join();
                oldAddrSpace->RestoreState();
                break;
            case SC_Create:
                arg1 = machine->ReadRegister(4);
                readString(arg1, file_name);
                DEBUG('s', "System Call: %s Invoking Create to file %s.\n",currentThread->getName(),file_name);
                if (!fileSystem->Create(file_name, 0)) {
                    syscall_has_fail = 1;
                }
                break;
            case SC_Open:
                DEBUG('s', "System Call: %s Invoking Open.\n",currentThread->getName());
                arg1 = machine->ReadRegister(4);
                readString(arg1, file_name);
                ret = open(file_name);
                if (ret == -1){
                    syscall_has_fail = 1;
                    break;
                }
                machine->WriteRegister(2, ret);
                break;
            case SC_Read:
                DEBUG('s', "System Call: %s Invoking Read.\n",currentThread->getName());
                // char *buffer
                arg1 = machine->ReadRegister(4);
                // int size
                arg2 = machine->ReadRegister(5);
                // OpenFileId
                arg3 = machine->ReadRegister(6);

                ret = read(&arg1,arg2,arg3);
                if (ret == -1){
                    syscall_has_fail = 1;
                    break;
                }
                machine->WriteRegister(2, ret);
                break;
            case SC_Write:
                DEBUG('s', "System Call: %s Invoking Write.\n",currentThread->getName());
                arg1 = machine->ReadRegister(4);
                arg2 = machine->ReadRegister(5);
                arg3 = machine->ReadRegister(6);
                char in_string[100];
                readString(arg1, in_string);
                ret = write(in_string, arg2, arg3);
                if (ret == -1){
                    syscall_has_fail = 1;
                    break;
                }
                break;
            case SC_Close:
                DEBUG('s', "System Call: %s Invoking Close.\n",currentThread->getName());
                arg1 = machine->ReadRegister(4);
                ret = close(arg1);
                if (ret == -1){
                    syscall_has_fail = 1;
                    break;
                }
                break;
            case SC_MySeek:
                DEBUG('s', "System Call: %s Invoking Lseek.\n",currentThread->getName());
                arg1 = machine->ReadRegister(4);
                arg2 = machine->ReadRegister(5);
                arg3 = machine->ReadRegister(6);
                ret = mySeek(arg1, arg2, arg3);
                if (ret == -1){
                    syscall_has_fail = 1;
                    break;
                }
                break; 
            case SC_Fork:
                DEBUG('s', "System Call: %s Invoking Fork.\n",currentThread->getName());
                printf("Exception Handler: %s  Fork\n",currentThread->getName());
                // Not Necessary !
                break;
            case SC_Yield:
                DEBUG('s', "System Call: %s Invoking Yield.\n",currentThread->getName());
                printf("Exception Handler: %s  Yield\n",currentThread->getName());
                // Not Necessary !
                break;
            default:
                machine->WriteRegister(2, -1);
                printf("Unknown syscall: %d\n", type);
                break;
        }
        if(syscall_has_fail){ 
            machine->WriteRegister(2, -1);
        }
        update_registers();
    } else {
        printf("Unexpected user mode exception %d %d\n", which, type);
        ASSERT(false);
    }
}
