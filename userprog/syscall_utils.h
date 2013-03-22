/* syscalls_utils.h 
 *
 *      Utility functions to read arguments from records upon a syscall *
 */
 
  

  /* Read a string char from memory */


char * readString(int dir, int * buff){
    //TODO make size variable!
    char aux[100]; 
    int i; i = 0;
    int tmp; tmp = 0;
    do{
         machine->ReadMem(dir + i, 1, &tmp);
         aux[i] = (char) tmp;

    } while(buff[i++] != '\0');

    printf("%d",4);
    return &buff[0];

 }

