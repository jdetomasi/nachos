#include "syscall.h"

int fid;
char from_file[100];

int main(){
    fid = Exec("../test/hola_mundo",0);
    fid = Exec("../test/halt",0);
    Exit(0);
}

