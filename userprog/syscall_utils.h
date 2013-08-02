/**
 * syscalls_utils.h 
 *
 */
 
#include "addrspace.h"
#define WRITEMEM(d,s,z) if (!machine->WriteMem(d,s,z)) ASSERT(machine->WriteMem(d,s,z));
#define READMEM(d,s,z) if (!machine->ReadMem(d,s,z)) ASSERT(machine->ReadMem(d,s,z));

void readBuffFromUsr(int addr, char *buff, int size);

void readString(int addr, char *buff);

void writeString(int addr, char *buff, int size);

void update_registers();
