#include "syscall.h"
int i;

int main(int argc, char* argv[]){

    for (i = 0; i < argc; i++){
        Write(argv[i], 5, ConsoleOutput);
        Write("\n", 1, ConsoleOutput);
    }
    Exit(0);
}
