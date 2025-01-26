#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("1.txt","w+");
    char buff[100];
    char *buf = "123456";
    setvbuf(fp,buff,_IOFBF,100);
    // fputs(buf,fp);
    fwrite(buf,strlen(buf),1,fp);
    while (1)
    {
        /* code */
    }
    
    return 0;
}
