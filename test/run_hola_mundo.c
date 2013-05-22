#include "syscall.h"

int fid;
char from_file[100];

int main(){
    fid = Exec("../test/hola_mundo");
    if(fid == 0){
        Create("si_senior");
    }
    Exit(0);
}

