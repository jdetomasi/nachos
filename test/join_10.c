#include "syscall.h"


int main(){
    int pid;
    int ret;
    pid = Exec("bin/run_hola_mundo",0,0,1);
    ret = Join(pid);

    if (ret == 0)
        pid = Exec("bin/hola_mundo",0,0,1);
    ret = Join(pid);
    // Should return 10
    Exit(ret + 5);
}


