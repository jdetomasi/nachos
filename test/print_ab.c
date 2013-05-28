#include "syscall.h"

int fid;

int main(){
    fid = Exec("../test/print_a");
    fid = Exec("../test/print_b");
    Exit(0);
}
