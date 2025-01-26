#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    //打开
    int fd = open("abc.c", O_RDWR | O_CREAT | O_APPEND );
    if(fd == -1){
        fprintf(stderr,"open abc.c error msg:%s\n",strerror(errno));
    }else{
        printf("open is success\n");
    }
    //写入
    char text[10];
    bzero(text,sizeof(text));
    for (int i = 0; i < 10; i++)
    {
        char temp[10];
        sprintf(temp,"黄坤%d ",i);
        strcpy(text,temp);
        ssize_t file_d = write(fd, text, strlen(text));
        if(file_d == -1){
            fprintf(stderr,"write abc.c error msg:%s\n",strerror(errno));
            break;
        }
        // else{
        //     printf("write is success,write in %ld\n",file_d);
        // }
        bzero(text,sizeof(text));
    }
    //读取
    char text1[128];
    long rel_a=lseek(fd,0,SEEK_SET);
    // printf("d:%ld\n",rel_a);
    bzero(text1,sizeof(text1));
    // memset(text1,0,sizeof(text1));
    int file_d1=read(fd,text1, sizeof(text1));
    if(file_d1 == -1){
        perror("11");
    }else{
        printf("read is success,read in %d\n",file_d1);
    }
    printf("abc.c: %s,字节数:%d\n",text1,file_d1);
    return 0;

}
