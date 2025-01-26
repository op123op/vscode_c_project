#include <stdio.h>

void sqort(int *arr,int lenght){
    int left = 0;
    for (int i = 0; i < lenght ; i++)
    {
        int min = left;//假设这是最小下标
        for (int j = left; j < lenght; j++)
        {//最小下标对应值比较数组从left下标开始每一个数如果比min的下标对应值小就更新最小下标
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        //把最小的值放到left位置,原本left对应的值放到min的位置
        int temp = arr[left]; 
        arr[left] = arr[min];
        arr[min] = temp;
        left++;//每次找到最小值后放到left的位置,放完后更新left让它自增加一    
    }
}
int main(int argc, char const *argv[])
{
    int arr[8] = {26,37,8,63,12,59,12,48};
    int lenght = sizeof(arr)/sizeof(int);//数组长度
    sqort(arr,lenght);
    printf("排序后：");
    for (int i = 0; i < lenght; i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}
