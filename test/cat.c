#include "syscall.h"
#define NULL        ((void*)0)

int main(int argc, char* argv[]) {
    OpenFileId fileId;
    int i;
    char ch;
    char buff[512];
    int chars_read;

    if (argc == 1) {
        // If was called without argument, it should work like echo
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
    } else {
        for (i = 1; i < argc; i++) {
            Write("\n", 1, ConsoleOutput);
            fileId = Open(argv[i]);
            while (Read(&ch, 1, fileId) == 1) {
                Write(&ch, 1, ConsoleOutput);
            }
            Close(fileId);
        }
        Write("\n", 1, ConsoleOutput);
        Exit(0);
    }
    return 0;
}
