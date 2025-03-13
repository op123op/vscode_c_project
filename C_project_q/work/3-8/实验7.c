#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 编写一个程序，将用户输入的天数转化为等价的星期数和剩余的天数。
    int day = 0;
    printf("请输入天数：");
    scanf("%d",&day);
    printf("%d星期零%d天\n",day / 7,day % 7);
    return 0;
}
