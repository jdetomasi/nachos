#include "syscall.h"

int fid;
char from_file[100];

int main(int argc, char* argv[]){
    fid = Exec("../test/hola_mundo",0);
    if(fid != -1){
        Create("test_files/si_senior");
        fid = Open("test_files/si_senior");
        Write("Hola! Soy el Thread Main!",25,fid);
    }
    Exit(0);
}

