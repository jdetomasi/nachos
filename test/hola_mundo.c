#include "syscall.h"

FilePosition MySeek(OpenFileId fd, FilePosition offset, int reference);

int main(){
    int fid;
    int ret;
    int readed;
    char from_file[100];

    Create("test_files/hola_mundo");
    fid = Open("test_files/hola_mundo");
    Write("Hola Mundo!", 11,fid);
    ret = MySeek(fid, 0, 0);
    if (ret >= 0)
        readed = Read(from_file,4,fid);
        ret = MySeek(fid, 7, 2);
        if (ret >= 0){
            Write(" - ",3,fid);
            Write(from_file,readed,fid);
            Write(" - ",3,fid);
        }
    Write(" Chau Mundo!", 12,fid);
    ret = MySeek(fid, 11, 1);
    if (ret >= 0)
        readed = Read(from_file,4,fid);
        ret = MySeek(fid, 7, 2);
        if (ret >= 0){
            Write(" - ",3,fid);
            Write(from_file,readed,fid);
            Write(" - ",3,fid);
        }
    Close(fid);
    Create("test_files/chau_mundo");
    fid = Open("test_files/chau_mundo");
    if(fid != -1){ 
        Write("Hola Mundo!", 11,fid);
        Write(" - Chau Mundo!", 14,fid);
        Close(fid);
    }
    /*
    ret = Read(from_file,4,fid);
    if (ret > 0)
        Write(from_file, ret, fid);
    Close(fid);
    */
    Exit(5);
}
