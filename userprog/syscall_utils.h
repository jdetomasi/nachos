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
void readString(int addr, char *buff){
  int tmp; tmp = 0;
  
  do{
    machine->ReadMem(addr, 1, &tmp);
    *buff = (char) tmp;
    buff++;
    addr++;
  } while(*(buff - 1) != '\0');
}
