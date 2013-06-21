#include "syscall.h"
#define NULL        ((void*)0)

char read_ignore_whitespaces();

int main(){
    int bg = 1;
    int i, j;
    int chars_read;
    int pid;
    char ch;
    char buff[128];
    int argc;
    char* argv[8];
    char cmd[64];
    char *prompt = "root@nachos:~# ";

    while (1) {

        // root@nachos:~# _
        Write(prompt, 15, ConsoleOutput);

        /*
         * command parsing
         */

        // specting excecutable file name, ignoring whitespaces
        ch = '\0';
        ch = read_ignore_whitespaces();

        // no entered text ?
        if (ch == '\n') {
            continue;
        }

        // user has entered some text, specting a command
        while(ch != '\n' && ch != ' '){
            cmd[chars_read] = ch;
            chars_read = chars_read + 1;
            Read(&ch, 1, ConsoleInput);
        }
        cmd[chars_read] = '\0';

        /*
         * argument parsing
         */ 

        // some arguments where entered
        i = 0;
        argc = 0;
        while (ch != '\n'){
            switch(ch) {
                case ' ':
                    buff[i] = '\0';
                    ch = read_ignore_whitespaces();
                    // whitespaces before \n ?
                    if (ch != '\n') {
                        argv[argc] = &buff[i + 1];
                        argc = argc + 1;
                    }
                    break;
                case '\0':
                    buff[i] = '\0';
                    Read(&ch, 1, ConsoleInput);
                    break;
                case '&':
                    bg = 0;
                    buff[i] = '\0';
                    break;
                case '\n':
                    buff[i] = '\0';
                    Read(&ch, 1, ConsoleInput);
                    break;
                default:
                    buff[i] = ch;
                    Read(&ch, 1, ConsoleInput);
                    break;
            }
            i = i + 1;
        }
        argv[argc] = NULL;

        // exit !
        if( cmd[0] == 'e' && cmd[1] == 'x' &&
            cmd[2] == 'i' && cmd[3] == 't' &&
            cmd[4] == '\0') Exit(0);

        // just for debug
        //Write(argv[0], 1, ConsoleOutput);
        //Write(argv[1], 1, ConsoleOutput);
        //Write(argv[2], 1, ConsoleOutput);

        pid = Exec(cmd, argc, argv, bg);

        if (pid == -1) {
            Write("No command \'", 12, ConsoleOutput);
            j = 0;
            while ((ch = cmd[j]) != '\0') {
                Write(&cmd[j], 1, ConsoleOutput);
                j = j + 1;
            }
            Write("\' found\n", 8, ConsoleOutput);
            continue;
        }

        if (bg == 1){
            Join(pid);
        }
        
    }
}

/*
 * reads chars from console ignoring whitespaces
 * returns the first non whitespace char entered 
 */
char read_ignore_whitespaces(){
    char ch;
    Read(&ch, 1, ConsoleInput);
    while (ch == ' ') {
        Read(&ch, 1, ConsoleInput);
    }
    return ch;
}
