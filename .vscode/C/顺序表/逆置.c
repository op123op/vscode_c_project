#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int lenght = sizeof(arr)/sizeof(int);
    int i = 0,left = 0,right = lenght - 1;
    while(i < lenght/2)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        ++left;
        --right;
        i++;
    }
    printf("逆置后：");
    for (int i = 0; i < lenght; i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}
