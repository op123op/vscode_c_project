#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fd = fopen("1.txt","w+");
    char buff[15] ;
    sprintf(buff,"hello123555");
    fwrite(buff,strlen(buff),1,fd);
    int len = ftell(fd);
    char msg[12] ;
    fseek(fd,0,SEEK_SET);
    // fread(msg,len,1,fd);
    // printf("%s%d\n",msg,len);

    // msg[0] = getchar();
    // msg[0] = getc(fd);
    // msg[0] = fgetc(fd);
    // printf("%c\n",msg[0]);

    // putc(65,fd);
    // putchar(65);
    // fputc(72,fd);
    // char *msg1 = "你好------------------------------------------";
    // fputs(msg1,fd);
    // puts(msg1);
    // gets(msg);
    fgets(msg,sizeof(msg),fd);
    int w = ftell(fd);
    printf("%s %d\n",msg,w);
    fclose(fd);
    return 0;
}
