#include "syscall.h"

int fid;
char from_file[100];

int main(){
    fid = Exec("../test/hola_mundo");
    if(fid != -1){
        Create("si_senior");
        fid = Open("si_senior");
        Write(fid, 25, "Hola! Soy el Thread Main!");
    }
    Exit(0);
}

