#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 编写一个程序，计算 1+2+3+4+…+n 的值。  
    while (1)
    {
        int num = 0;
        int ret_n  = 0;
        // 1、请输入要计算的数据
        printf("请输入一个数：\n");
        while ( ret_n!=1 )                                         
        {
            ret_n = scanf("%d", &num);   
            if (ret_n != 1)
            {
                printf("输入错误，请重新输入。\n");                                                 
            }
            while(getchar()!='\n');             
        }
        ret_n = 0;
        int sum = 0;
        for (int i = 1; i <= num; i++)
        {
            sum = i + sum;
        }
        printf("1+2+3+4+…+n n=%d时和为：%d\n", num, sum);
        
    }
    return 0;
}
