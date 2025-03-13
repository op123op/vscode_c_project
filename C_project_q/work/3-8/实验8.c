#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 编写一个程序，用户输入华氏温度F，程序输出摄氏温度C，结果保留2位小数。
    int fahrenheit = 0;
    printf("请输入一个华式度：");
    scanf("%dF",&fahrenheit);
    while (getchar()!='\n');
    float Degree_Celsius = 5 * (fahrenheit - 32) / 9.0;
    printf("摄氏度为：%.2f℃\n",Degree_Celsius);
    return 0;
}
