#include "syscall.h"

int pid;
int ret;

int main(){
    pid = Exec("../test/print_a",0,0,1);
    if (pid != -1){
        ret = Join(pid);
        // Should not happen
        Halt();
    }
    // Should not be reacheable
    Exit(-1);
}


