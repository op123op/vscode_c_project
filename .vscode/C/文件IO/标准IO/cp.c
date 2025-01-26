#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <strings.h>

#define MAX 128
int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("参数传递异常\n");
        return -1;
    }
    
    FILE *file1 = fopen(argv[1],"r");
    FILE *file2 = fopen(argv[2],"w+");
    
    if (file1 == NULL | file2 == NULL)
    {
        fprintf(stderr,"打开%s或%s文件失败:%s",argv[1],argv[2],strerror(errno));
        return -1;
    }
    char buff[MAX];
    size_t ret_val = 1;
    while (ret_val >= 1)
    {
        ret_val = fread(buff,1,ret_val,file1);
        if (ret_val < 1)
        {
            if (!feof(file1))
            {
                if (ferror(file1))
                {
                    perror("粘贴失败");
                    return -1;
                }
                   
            }else{
                fwrite(buff,1,ret_val,file2);
                if (!feof(file2))
                {
                    if (ferror(file2))
                    {
                        perror("写入失败");
                        return -1;
                    }else{
                        printf("写入成功\n");
                    }
                    
                }
                break;
            }   
        }
        fwrite(buff,1,ret_val,file2);
        // bzero(buff,0);
    }
    
    fclose(file1);
    fclose(file2);
    return 0;
}
