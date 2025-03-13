#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // 编程实现如下功能：
    // - 如果用户输入大小写字母，则输出字母对应的ASCII码值。
    // - 如果用户输入ASCII码值，则输出对应的大小写字母。
    printf("请输入：");
    char a = getchar();
    char str[8] = {0};
    int i = 0,num = 0;
    if (('A' <= a && a <= 'Z') || ('a' <= a && a <= 'z'))
    {
        printf("字符%c对应的ASCII码为：%d\n", a, a);
    }else if ('0' <= a && a <= '9')
    {
        while ( a !='\n')
        {
            str[i] = a;
            a = getchar();
            i++;
        }
        num = atoi(str);
        printf("%d码值对应的字符为：%c\n", num, num);
    }
    
    
    return 0;
}
