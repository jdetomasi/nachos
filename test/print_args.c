#include "syscall.h"

int main(int argc, char* argv[]){
    int i;

    for (i = 0; i < argc; i++){
        Write(argv[i], 5, ConsoleOutput);
        Write("\n", 1, ConsoleOutput);
    }
    Exit(0);
}
