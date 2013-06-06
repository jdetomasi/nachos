#include "syscall.h"

int pid;
int ret;

int main(){
    pid = Exec("../test/run_hola_mundo",1,0,1);
    ret = Join(pid);

    if (ret == 0)
        pid = Exec("../test/hola_mundo",1,0,1);
    ret = Join(pid);
    // Should return 10
    Exit(ret + 5);
}


