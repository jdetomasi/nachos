
#include "syscall.h"


int main(){
    int fid;
    char from_file[100];

    fid = Exec("../test/hola_mundo",0,0,0);
    fid = Exec("../test/run_hola_mundo",0,0,0);
    fid = Exec("../test/join_10",0,0,0);
    fid = Exec("../test/print_a",0,0,0);
    fid = Exec("../test/halt",0,0,0);
    Exit(0);
}

