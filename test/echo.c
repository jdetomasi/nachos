#include "syscall.h"
#define NULL        ((void*)0)

int main(){

    char buff[512];
    int chars_read;
    char ch;
    while (1) {
        chars_read = 0;
        *buff = NULL;
        ch = '\0';
        while(ch != '\n' && chars_read < 512){
            Read(&ch, 1, ConsoleInput);
            buff[chars_read] = ch;
            chars_read = chars_read + 1;
        }
        buff[chars_read] = '\0';
        Write(buff, chars_read, ConsoleOutput);

        // exit !
        if( buff[0] == 'e' && buff[1] == 'x' &&
            buff[2] == 'i' && buff[3] == 't' &&
            buff[4] == '\n') Exit(0);
    }
}
