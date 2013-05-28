#include "syscall.h"

int fid;
char from_file[100];

int main(){
    fid = Exec("../test/halt");
    if(fid == 0){
        Create("si_senior");
    }
    Exit(0);
}

