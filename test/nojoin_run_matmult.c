#include "syscall.h"
#define LEN    20 

int main(){
    int fid[LEN];
    int ret;
    int i;
    ret = LEN;
    for(i=0; i < LEN; i++){
        fid[i] = Exec("bin/matmult",0,0,0);
    }
    Exit(ret);
}

