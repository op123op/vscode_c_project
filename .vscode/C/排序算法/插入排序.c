#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//显示函数
void show(int arr[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

//插入排序
void insert_sort(int arr[],int len){
    if (len <= 1)
    {
        return ;
    }
    int i,j;
    for (i = 1; i < len; i++)
    {
        int tmp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] < tmp)
            {
                break;
            }else{
                arr[j+1] = arr[j];
            }
        }
        arr[j+1] = tmp;
    }
    
}

int main(int argc, char const *argv[])
{
    int data[10];
    int len = sizeof(data)/sizeof(int);
    srand(time(NULL));          //生成随机数种子
    for (int i = 0; i < len; i++)
    {
        data[i] = rand()%100;
    }
    
    //排序前
    printf("排序前: ");
    show(data,len);
    insert_sort(data,len);

    //排序后
    printf("\n排序后: ");
    show(data,len);
    return 0;
}
