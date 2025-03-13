#include <stdio.h>

#define NA 6.022e23L
int main(int argc, char const *argv[])
{
    // 编写一个程序，计算N升纯净水所包含的分子个数，结果用科学计数法表示。
    int num = 0;
    long double f1 = 0.0;
    printf("请输入：");
    scanf("%d", &num);
    f1 = 1 * (num*1000 / 18) * (NA / 1);
    printf("%d升水有%Le个分子\n", num,f1);
    return 0;
}
