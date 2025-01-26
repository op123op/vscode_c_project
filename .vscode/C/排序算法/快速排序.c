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

//交换函数
int partition(int arr[],int len){
    if (len <= 1)
    {
        return 0;
    }
    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        while (arr[i] <= arr[j] && i < j)
            j--;
        swap(&arr[j],&arr[i]);
        while (arr[i] <= arr[j] && i < j)
            i++;
        swap(&arr[j],&arr[i]);
    }
    return i;
}

//快速排序
void quick_sort(int arr[],int len){
    if (len <= 1)
    {
        return ;
    }
    
    int par = partition(arr,len);
    quick_sort(arr,par);
    quick_sort(arr+par+1,len-par-1);
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
    quick_sort(data,len);

    //排序后
    printf("\n排序后: ");
    show(data,len);
    puts("");
    return 0;
}