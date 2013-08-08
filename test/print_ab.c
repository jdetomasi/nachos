#include "syscall.h"


int main(){
    int fid;
    fid = Exec("../test/print_a",0, 0, 0);
    fid = Exec("../test/print_b",0, 0, 0);
    Exit(0);
}
