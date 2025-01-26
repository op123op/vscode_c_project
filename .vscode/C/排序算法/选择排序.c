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

//选择排序
void select_sort(int arr[],int len){

    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i+1; j < len; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i],&arr[min]);
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
    select_sort(data,len);

    //排序后
    printf("\n排序后: ");
    show(data,len);
    puts("");
    return 0;
}