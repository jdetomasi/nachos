#include "syscall.h"

#define NULL        ((void*)0)
int fid;

int main(){
   char *argv[] = {"hola", "mundo", "!!!", NULL};   
   fid = Exec("../test/print_args", 3, argv, 0);
   Exit(0);
}
