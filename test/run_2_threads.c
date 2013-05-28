#include "syscall.h"

int fid;
char from_file[100];

int main(){
    fid = Exec("../test/hola_mundo");
    fid = Exec("../test/halt");
    Exit(0);
}

