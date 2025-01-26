#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("参数不正确\n");
        return -1;
    }
    struct stat file_info;
    int dp = stat(argv[1],&file_info);
    if (dp == -1)
    {
        perror("查看文件失败");
        return -1;
    }
    
    if (S_ISREG(file_info.st_mode))
    {
        printf("-");
        char rwx[] = {'r','w','x'};
        for (int i = 0; i < 9; i++)
        {
            printf("%c",file_info.st_mode&(0400>>i) ? rwx[i%3] : '-');
        }
    }
    
    printf("\n");
    return 0;
}
