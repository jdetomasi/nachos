#include "syscall.h"
#define NULL        ((void*)0)
char ch;
char buff[128];
int i;
int argc;
int argv[10];
int fid;

int main(){
    fid = Open("test_files/c_out");
    Write("COMENZANDO:\n", 12, fid);
    Write("root@nachos:~# ",15, fid);
    Write("root@nachos:~# ",15,ConsoleOutput);
    while (1) {
        ch = '\0';
        i = 0;
        argc = 0;
        argv[0] = &buff[0];
        while (ch != '\n') {
            Read(&ch, 1, ConsoleInput);
            //Write(&ch, 1, fid);
            if (ch = ' ') {
                buff[i] = '\0';
                argc = argc + 1;
                argv[argc] = &buff[i + 1];
            }
            buff[i] = ch;
            i = i + 1;
        }
        argv[argc + 1] = NULL;
        //Exec(argv[0], argc, argv, 0);
    }
}

