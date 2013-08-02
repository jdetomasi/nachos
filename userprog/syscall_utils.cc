/**
 * syscalls_utils.h 
 *
 *   Utility functions to read arguments from records upon a syscall 
 */

/**
 * Read a string from memory
 * @param dir Memory address of the first element of the sting. 
 * @param buff Pointer where result string will be returned. 
 * @return ??? TODO!!!
 */
#include "system.h"
#include "syscall_utils.h"
#include "addrspace.h"
#include "machine.h"
#include <map>

void readBuffFromUsr(int addr, char *buff, int size){
  int tmp; tmp = 0;
  
  do{
    READMEM(addr, 1, &tmp);
    addr++;
    *buff = (char) tmp;
  } while(*(buff++) != '\0' && --size > 0);
}

//readStrFromUsr
void readString(int addr, char *buff){
  int tmp; tmp = 0;
  do{

    READMEM(addr, 1, &tmp);
    addr++;
    *buff = (char) tmp;
  } while(*(buff++) != '\0');
}

// writeBuffToUsr
void writeString(int addr, char *buff, int size){
  for (int i = 0; i < size; i++) {
  	WRITEMEM(addr, 1, (int) *buff);
  	buff++;
  	addr++;
  }
}

void update_registers(){

    machine->WriteRegister(PrevPCReg, machine->ReadRegister(PCReg));
    machine->WriteRegister(PCReg, machine->ReadRegister(NextPCReg));
    machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg)+4);
}

