#include "syscall.h"

int main(int argc, char* argv[]){

    Write(argc, 1, ConsoleOutput);
    Write(argv[0], 5, ConsoleOutput);
    Exit(0);
}

