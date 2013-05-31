#include "syscall.h"

int fid;
char from_file[100];

int main(int argc, char* argv[]){
    fid = Exec("../test/halt",0);
    Exit(0);
}
