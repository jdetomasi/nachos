#include "syscall.h"


int main(int argc, char* argv[]){
    int fid;
    char from_file[100];
    fid = Exec("../test/halt",0,0,0);
    Exit(0);
}
