#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[8] = {26,37,8,63,12,59,12,48};
    int legth = sizeof(arr)/sizeof(int);
    int temp =0;
    for (int i = 0; i < legth - 1; i++)
    { 
        for (int j = 0; j < legth -1 - i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
            }
        }
    }
    printf("排序后：");
    for (int i = 0; i < legth; i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}
