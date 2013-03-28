#include "syscall.h"

int fid;
char from_file[100];

int main(){
    //Create("hola_mundo");
    fid = Open("hola_mundo");
    //Write("Hola Mundo!", 11,fid);
    //Write("Chau", 4,fid);
    Read(from_file,4,fid);
    Write(from_file, 4,fid);
    Close(fid);
    Exit(0);
}
