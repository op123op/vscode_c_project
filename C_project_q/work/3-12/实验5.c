#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N = 0,i = 0;
    while (1)
    {
        printf("请输入一个非零整数：");
        int ret = scanf("%d",&N);
        if (ret != 1 && N == 0)
        {
            printf("请重新输入一个非零整数!!!\n");
            while(getchar()!='\n');
        }else{
            break;
        }
    }
    printf("自然数%d：",N);
    while (N != 0 && N != 1)
    {
        if (N%2 == 0)
        {
            N = N/2;
            i++;
        }else 
        {
            N = N*3 + 1;
            i++;
        }
        printf("%d ",N);
    }
    printf(",自然数到达4-2-1谷底所经过的变换次数：%d\n",i);
    
    return 0;
}
