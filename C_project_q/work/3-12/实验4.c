#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 0;
    while (1)
    {
        printf("请输入一个整数：");
        int ret = scanf("%d",&num);
        if (ret != 1)
        {
            printf("请重新输入一个整数!!!\n");
        }else{
            break;
        }
    }
    printf("1~%d的素数有：",num);
    for (int i = 2; i <= num; i++)
    {
        int n = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                n++;
            }
        }
        if (n == 2)
        {
            printf("%d ",i);
        }
        
    }
    printf("\n");
    
    return 0;
}