#include "syscall.h"

int main(int argc, char* argv[]) {
    OpenFileId fileId;
    int i;
    char ch;

    if (argc == 1) {
        while(1) {
            Read(&ch, 1, ConsoleInput);
            Write(&ch, 1, ConsoleOutput);
            if (ch != '\n')
                Write("\n", 1, ConsoleOutput);
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
