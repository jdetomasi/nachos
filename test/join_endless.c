#include "syscall.h"


int main(){
    int pid;
    int ret;
    pid = Exec("bin/print_a",0,0,1);
    if (pid != -1){
        ret = Join(pid);
        // Should not happen
        Halt();
    }
    // Should not be reacheable
    Exit(-1);
}


