#include "syscall.h"


int main(){
    int fid;
    fid = Exec("bin/print_a",0, 0, 0);
    fid = Exec("bin/print_b",0, 0, 0);
    Exit(0);
}
