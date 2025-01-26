#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#define SIZE_MAX 128

int main(int argc, char const *argv[])
{
    int fd = open(argv[1],O_RDONLY );
    int fd1 = open(argv[2],O_WRONLY | O_CREAT,0666);
    if(fd == -1){
        fprintf(stderr,"打开%s文件失败: %s\n",argv[1],strerror(errno));
        return 0;
    }
    if(fd1 == -1){
        fprintf(stderr,"打开%s文件失败: %s\n",argv[2],strerror(errno));
        return 0;
    }
    char msg[SIZE_MAX] ;
    size_t rea_vl = SIZE_MAX;
    while (rea_vl >= SIZE_MAX)
    {
        rea_vl = read(fd,msg,SIZE_MAX);
        if(rea_vl == -1){
            fprintf(stderr,"文件%s读取失败: %s\n",argv[1],strerror(errno));
            break;
        }else{
            printf("读取%ld个字节\n",rea_vl);
        }
        rea_vl = write(fd1,msg,rea_vl);
        if(rea_vl == -1){
            fprintf(stderr,"文件%s写入失败: %s\n",argv[2],strerror(errno));
            break;
        }else{
            printf("写入%ld个字节\n",rea_vl);
        }
    }
    
    close(fd);
    close(fd1);
    return 0;
}
