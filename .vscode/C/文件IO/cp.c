#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd = open(argv[1],O_RDONLY );
    int fd1 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0666);
    if(fd1 == -1){
        perror("err: ");
    }
    long s = lseek(fd,0,SEEK_END);
    char text[s];
    lseek(fd,0,SEEK_SET);
    bzero(text,sizeof(text));
    read(fd,text,s);
    printf("00%s",text);
    write(fd1,text,s);
    close(fd);
    close(fd1);
    return 0;
}
