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
                DEBUG('a', "System Call: [pid] invoked Halt.\n");
                halt(); 
                break;
            case SC_Exit:
                DEBUG('a', "System Call: [pid] invoked Exit.\n");
                machine->WriteRegister(2, machine->ReadRegister(4));
                printf("Exception Handler: Exit with value %d\n", machine->ReadRegister(4));
                currentThread->Finish();
                //      deallocate physical memory. It is sufficient with next line?
                //      Ver como pasar la info de return a un eventual thread que haga join sobre el que hace exit
                delete currentThread;
                break;
            case SC_Exec:
                DEBUG('a', "System Call: [pid] invoked Exec.\n");
                printf("Exception Handler: Exec\n");
                // arg1 :: char * the name of the file that stores the executable .
                arg1 = machine->ReadRegister(4);
                readString(arg1, file_name);
                openedFiles[last_open] = fileSystem->Open(file_name);
                oldAddrSpace = currentThread->space;
                newAddrSpace = new AddrSpace(openedFiles[last_open]);
                newThread = new Thread(file_name);
                last_open++;
                newThread->space = newAddrSpace;
                machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
                machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
                machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
                currentSpaces[last_space] = newAddrSpace;
                machine->WriteRegister(2,last_space);
                last_space++;
                oldAddrSpace->SaveState();
                newAddrSpace->InitRegisters();
                oldAddrSpace->RestoreState();
                machine->Run();
                break;
            case SC_Join:
                DEBUG('a', "System Call: [pid] invoked Join.\n");
                printf("Exception Handler: Join\n");
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
                DEBUG('a', "System Call: [pid] invoked Create.\n");
                arg1 = machine->ReadRegister(4);
                readString(arg1, file_name);
                if (!fileSystem->Create(file_name, 0)) {
                    syscall_has_fail = 1;
                }
                break;
            case SC_Open:
                DEBUG('a', "System Call: [pid] invoked Open.\n");
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
                DEBUG('a', "System Call: [pid] invoked Read.\n");
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
                DEBUG('a', "System Call: [pid] invoked Write.\n");
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
                DEBUG('a', "System Call: [pid] invoked Close.\n");
                arg1 = machine->ReadRegister(4);
                ret = close(arg1);
                if (ret == -1){
                    syscall_has_fail = 1;
                    break;
                }
                break;
            case SC_MySeek:
                DEBUG('a', "System Call: [pid] invoked Lseek.\n");
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
                DEBUG('a', "System Call: [pid] invoked Fork.\n");
                printf("Exception Handler: Fork\n");
                // Not Necessary !
                break;
            case SC_Yield:
                DEBUG('a', "System Call: [pid] invoked Yield.\n");
                printf("Exception Handler: Yield\n");
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
