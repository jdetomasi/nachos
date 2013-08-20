
#include "syscall.h"


int main(){
    int fid;
    char from_file[100];

    fid = Exec("bin/hola_mundo",0,0,0);
    fid = Exec("bin/run_hola_mundo",0,0,0);
    fid = Exec("bin/join_10",0,0,0);
    fid = Exec("bin/print_a",0,0,0);
    fid = Exec("bin/halt",0,0,0);
    Exit(0);
}

