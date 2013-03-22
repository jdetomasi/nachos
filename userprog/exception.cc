// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
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

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------

void
ExceptionHandler(ExceptionType which){

        ASSERT(interrupt->getStatus() == SystemMode);
	int type = machine->ReadRegister(2);
        int arg_1,arg_2,arg_3,pc;

	if (which == SyscallException) {
		switch(type){
			case SC_Halt:
                                DEBUG('a', "System Call: [pid] invoked Halt.\n");
				interrupt->Halt();
				break;
			case SC_Exit:
                                DEBUG('a', "System Call: [pid] invoked Exit.\n");
				machine->WriteRegister(2, machine->ReadRegister(4));
				printf("Exception Handler: Exit with value %d\n", machine->ReadRegister(4));
                                currentThread->Finish();
                                // TODO deallocate physical memory. It is sufficient with next line?
                                delete currentThread;
				break;
			case SC_Exec:
                                DEBUG('a', "System Call: [pid] invoked Exec.\n");
				printf("Exception Handler: Exec\n");
				// TODO !
				break;
			case SC_Join:
                                DEBUG('a', "System Call: [pid] invoked Join.\n");
				printf("Exception Handler: Join\n");
				// TODO !
				break;
			case SC_Create:
                                DEBUG('a', "System Call: [pid] invoked Create.\n");
				printf("Exception Handler: Create\n");
				// TODO !
				break;
			case SC_Open:
                                DEBUG('a', "System Call: [pid] invoked Open.\n");
                                arg_1 = machine->ReadRegister(4);
                                //char *file_name;
                                //file_name = readString(arg_1);
				// TODO !
				break;
			case SC_Read:
                                DEBUG('a', "System Call: [pid] invoked Read.\n");
				printf("Exception Handler: Read\n");
				// TODO !
				break;
			case SC_Write:
                                DEBUG('a', "System Call: [pid] invoked Write.\n");
                                pc = machine->ReadRegister(34);
                                arg_1 = machine->ReadRegister(4);
                                arg_2 = machine->ReadRegister(5);
                                arg_3 = machine->ReadRegister(6);
                                char in_buff[100];
                                readString(arg_1, in_buff);
				printf("Exception Handler: Write %s - %d - %d\n",in_buff,arg_2,arg_3);
                                //printf("%s\n", readString(arg_1));
				machine->WriteRegister(2, 0);
				// TODO !
				break;
			case SC_Close:
                                DEBUG('a', "System Call: [pid] invoked Close.\n");
				printf("Exception Handler: Close\n");
				// TODO !
				break;
			case SC_Fork:
                                DEBUG('a', "System Call: [pid] invoked Fork.\n");
				printf("Exception Handler: Fork\n");
				// TODO !
				break;
			case SC_Yield:
                                DEBUG('a', "System Call: [pid] invoked Yield.\n");
				machine->WriteRegister(2, 0);
                                // TODO deallocate physical memory
                                currentThread->Yield();
				break;
			default:
				machine->WriteRegister(2, -1);
				printf("Unknown syscall: %d\n", type);
				break;
			}

	        machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
	} else {
		printf("Unexpected user mode exception %d %d\n", which, type);
		ASSERT(false);
	}
}
