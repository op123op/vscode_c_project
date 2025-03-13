#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 完成交换两个int数据的功能(三种以上的方法)
    // 1、
    // int a, b, tmp;
    // printf("请输入两个数：");
    // scanf("%d %d",&a,&b);
    // while (getchar() != '\n');
    // printf("交换前 a = %d,b = %d\n",a ,b);
    // tmp = a;
    // a = b;
    // b = tmp;
    // printf("交换后 a = %d,b = %d\n",a ,b);

    // // 2.加法
    // int a1, b1;
    // printf("请输入两个数：");
    // scanf("%d %d",&a1,&b1);
    // while (getchar() != '\n');
    // printf("交换前 a1 = %d,b1 = %d\n",a1 ,b1);
    // a1 = a1 + b1;
    // b1 = a1 - b1;
    // a1 = a1 - b1;

    // printf("交换后 a1 = %d,b1 = %d\n",a1 ,b1);

    // 3.异或
    int a2, b2;
    printf("请输入两个数：");
    scanf("%d %d",&a2,&b2);
    printf("交换前 a2 = %d,b2 = %d\n",a2 ,b2);
    a2 = a2 ^ b2;
    b2 = a2 ^ b2;
    a2 = a2 ^ b2;

    printf("交换后 a2 = %d,b2 = %d\n",a2 ,b2);
    return 0;
}
