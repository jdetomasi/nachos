#include "syscall.h"

int main(){
    int fid;
    Create("/tmp/asd");
    fid = Open("/tmp/asd");
    while(1){
        Write("a", 1, fid);
    }
    Exit(0);
}

