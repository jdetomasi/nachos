#include "syscall.h"
int i;

int main(int argc, char* argv[]){

    Write(argc, 1, ConsoleOutput);
    for (i = 0; i < argc; i++){
        Write("\n", 1, ConsoleOutput);
        Write(argv[i], 5, ConsoleOutput);
    }
    Exit(0);
}

