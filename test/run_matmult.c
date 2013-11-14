#include "syscall.h"
#define LEN     10

int main(){
    int fid[LEN];
    int ret;
    int i;
    for(i=0; i < LEN; i++){
        fid[i] = Exec("bin/matmult",0,0,1);
    }
    for(i=0; i < LEN; i++){
        ret += Join(fid[i]);
    }
    if (ret == LEN * 810){
        Write("Finalizando con valor correcto!!\n", 33,ConsoleOutput);
    }
    Exit(ret);
}

