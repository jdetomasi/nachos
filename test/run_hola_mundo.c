#include "syscall.h"

int fid;
char from_file[100];

int main(){
    Exec("../test/hola_mundo");
    Exit(0);
}

