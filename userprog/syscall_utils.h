/**
 * syscalls_utils.h 
 *
 */
 
#include "addrspace.h"

void readBuffFromUsr(int addr, char *buff, int size);

void readString(int addr, char *buff);

void writeString(int addr, char *buff, int size);

void update_registers();
