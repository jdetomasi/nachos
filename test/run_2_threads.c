#include "syscall.h"

int fid;
char from_file[100];

int main(){
    fid = Exec("../test/halt",0,0,0);
    fid = Exec("../test/hola_mundo",0,0,0);
    fid = Exec("../test/print_a",0,0,0);
    Exit(0);
}

