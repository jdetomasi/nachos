#include "syscall.h"

int fid;

int main(){
    fid = Exec("../test/print_a",0);
    fid = Exec("../test/print_b",0);
    Exit(0);
}
