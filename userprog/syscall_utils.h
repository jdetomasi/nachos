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
#include "addrspace.h"

extern int last_space;
extern AddrSpace *currentSpaces[100];

void readString(int addr, char *buff);

void writeString(int addr, char *buff, int size);

void update_registers();
