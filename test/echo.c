#include "syscall.h"

char ch;

int main(){

    for (;;) {
        Read(&ch, 1, ConsoleInput);
        Write(&ch, 1, ConsoleOutput);
        Write("\n", 1, ConsoleOutput);
	if (ch == 'q') return;  // if q, quit
        ch = ' ';
    }
}
