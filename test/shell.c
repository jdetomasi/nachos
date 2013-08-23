#include "syscall.h"
#define NULL        ((void*)0)
#define SBIN        "bin/"
#define SBINLEN     4

char read_ignore_whitespaces();

int main(){
    int bg = 1;
    int i, j;
    int chars_read;
    int pid;
    char ch;
    static char buff[128];
    int argc;
    char* argv[8];
    char cmd[64];
    char *prompt = "root@nachos:~# ";
    char *argv_aux[] = {"test_files/hola_mundo", "test_files/si_senior", NULL};   

    while (1) {

        // Emptying variables...
        //
        *cmd = NULL;
        ch = '\0';
        argc = 0;
        chars_read = 0;
        buff[0] = '\0';

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
                    if (ch != '\n' && ch != '&') {
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
                    ch = '\n';
                    break;
                default:
                    buff[i] = ch;
                    Read(&ch, 1, ConsoleInput);
                    break;
            }
            i = i + 1;
        }
        // Arguments ended in the previous iteration
        buff[i - 1] = '\0';
        argv[argc] = NULL;

        // exit !
        if( cmd[0] == 'e' && cmd[1] == 'x' &&
            cmd[2] == 'i' && cmd[3] == 't' &&
            cmd[4] == '\0') Exit(0);
        
        //pid = Exec("bin/cat", 2, argv_aux, 1);
        pid = Exec(cmd, argc, argv, bg);

        // search cmd in test/ just in case path was not full
        if (pid == -1) {
            if (chars_read < 59){
                for (j = chars_read;  j >= 0; j--){
                    cmd[j + SBINLEN] = cmd[j];
                }
                for (j = 0; j < SBINLEN; j++){
                    cmd[j] = SBIN[j];
                }
            }
            pid = Exec(cmd, argc, argv, bg);
        }
        if (pid == -1) {
            j = 0;
            while ((ch = cmd[j]) != '\0') {
                Write(&cmd[j], 1, ConsoleOutput);
                j = j + 1;
            }
            Write(": Command not found\n'", 20, ConsoleOutput);
            continue;
        }

        if (bg == 1){
            Join(pid);
        } else{
            bg = 1;
            ch = '\0';
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
