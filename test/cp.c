#include "syscall.h"

int main(int argc, char* argv[]) {
    OpenFileId fileId, destId;
    int i;
    char ch;

    if (argc != 3) {
        Write("cp: bad usage\n", 14, ConsoleOutput);
        Write("Usage: cp <input file> <destination file>\n",42, ConsoleOutput);
        Exit(-1);
    } else {
        fileId = Open(argv[1]);
        if (fileId == -1){
            Write("Could't open file ",18,ConsoleOutput);
            for(i=0;argv[1][i] != '\0'; i++){
                Write(&argv[1][i],1,ConsoleOutput);
            }
            Write("\n",1,ConsoleOutput);
            Exit(-1);
        }else{
            Create(argv[2]);
            destId = Open(argv[2]);
            while (Read(&ch, 1, fileId) == 1) {
                Write(&ch, 1, destId);
            }
            Close(fileId);
            Close(destId);
            Exit(0);
        }
    }
}
