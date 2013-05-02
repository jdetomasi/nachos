#include "syscall.h"

int fid;
int ret;
int readed;
char from_file[100];

int main(){
    Write("Puto el que lee!\n", 17,1);
    Write(" FIN! \n", 6,1);
    Exit(0);
    Halt();
}
