#include "syscall.h"
#define NULL        ((void*)0)

int main(){
    int bg = 1;
    int i;
    int pid;
    char ch;
    char buff[128];
    int argc;
    int argv[8];
    char cmd[64];
    char * prompt = "root@nachos:~# ";

    while (1) {
        Write(prompt, 15, ConsoleOutput);
        ch = '\0';
        i = 0;
        /*
        // Iddle wait, ignore blank spaces
        while (ch = ' '){ 
            Read(&ch, 1, ConsoleInput);
            if(ch == '\n'){
                Write(prompt, 15, ConsoleOutput);
            }
            else{
                break;
            }
        }
        */

        while( ch != '\n' && ch != ' '){
            Read(&ch, 1, ConsoleInput);
            cmd[i++] = ch;
        }
        cmd[i - 1] = '\0'; 

        i = argc = 0;
        while (ch != '\n'){
            if (ch == ' '){
                buff[i] = '\0';
                argv[argc] = &buff[i + 1];
                argc = argc + 1;
            } else if (ch == '\n'){
                buff[i] = '\0';
                break;
            } else if (ch == '&'){
                bg = 0;
                break;
            }
            Read(&ch, 1, ConsoleInput);
            buff[i] = ch;
            i = i + 1;
        }
        argv[argc] = NULL;
        argc = argc - 1;

        pid = Exec(cmd, argc, argv, bg);
        if (bg == 1){
            Join(pid);
        }
        
    }
}
