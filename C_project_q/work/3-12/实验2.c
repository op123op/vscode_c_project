#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch1 = 0;
    while (1)
    {
        printf("请输入一个大写字母：");
        scanf("%c",&ch1);
        if ( ch1 >= 65 && ch1 <= 90)
            break;
        else{
            printf("请输入大写字母！！\n");
            while (getchar()!='\n');
        }  
    }
    for (int i = 0; i <= ch1-'A'; i++)
    {
        for (int j = ch1-'A'-i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < (i+1); k++)
        {
            printf("%c",'A'+k);
        }
        if (i >= 1)
        {
            for (int k = i; k > 0; k--)
            {
                printf("%c",'A'+k-1);
            }
        }
        printf("\n");
    }
    
    return 0;
}
