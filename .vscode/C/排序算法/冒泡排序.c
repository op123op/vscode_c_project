#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//交换函数
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//显示函数
void show(int arr[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

//冒泡排序
void bubble_sort(int arr[],int len){
    if (len <= 1)
    {
        return ;
    }
    int k = 0;
    while (1)
    {
        int done = 1;
        for (int i = 0; i < len-1-k; i++)
        {
            if (arr[i] <= arr[i+1])
            {
                continue;
            }
            swap(&arr[i],&arr[i+1]);
            done = 0;
        }

        if (done)
        {
            break;
        }
        
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
    bubble_sort(data,len);

    //排序后
    printf("\n排序后: ");
    show(data,len);
    puts("");
    return 0;
}