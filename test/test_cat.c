#include "syscall.h"
#define NULL        ((void*)0)

int main(){
    int pid;
    char *argv_aux[] = {"test_files/hola_mundo", "test_files/si_senior", NULL};   
    pid = Exec("bin/cat", 2, argv_aux, 1);
    Join(pid);
    Exit(99);        
}
