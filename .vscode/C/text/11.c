#include <stdio.h>
#include <string.h>

// char*GetMemory( void){
//     char p[] ="hello world";
//     return p;
// }

// void Test( void){
//     char*str=NULL;
//     str=GetMemory();
//     printf( str);
// }
#define SUM(a) ((a)++)

int main(int argc, char const *argv[])
{
    char a = 1;
    char b = 'a';
    // SUM(a);
    int arr[2] = {0xff};
    // Test();
    printf("%d\a %c\n",b,a);
    return 0;
}
