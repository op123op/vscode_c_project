#include <stdio.h>

int main(int argc, char const *argv[])
{
    char a = 'a';
    printf("26小写字母为：");
    while ( a <= 122)
    {
        printf("%c ", a);
        a = a + 1;
    }
    printf("\n");
    return 0;
}
