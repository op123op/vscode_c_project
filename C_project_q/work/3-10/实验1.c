#include <stdio.h>
int main(void)
{
    int x = 10;
    int a, b, c;
    a = x++;        
    b = ++x;        
    c = 10*x++;     
    printf("x=%d，a=%d，b=%d，c=%d\n", x, a, b, c);
    //                      x = 13, a = 10, b =12, c = 120
    return 0;
}