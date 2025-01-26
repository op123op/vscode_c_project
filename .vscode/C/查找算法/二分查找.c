#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * rand_num(int size) {
    // 初始化数组
    int *arr = calloc(size,sizeof(int));

    // 设置随机数种子
    srand((unsigned int)time(NULL));

    // 生成随机数并填充数组
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // 生成一个0到99的随机数
    }

    // 打印原始数组
    printf("原始数组: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 对数组进行排序（升序）
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换两个元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 打印排序后的数组
    printf("排序后的数组: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return arr;
}


int main(int argc, char const *argv[])
{
    // int* arr= rand_num(50);
    int a=0,let,temp;
    int arr[50]={4, 5, 5 ,7, 13 ,16 ,17 ,18, 21, 24, 25, 25, 31, 33 ,36 ,39 ,40, 44 ,46 ,46, 56, 57, 57, 59 ,59 ,60, 64, 65 ,67 ,68 ,68 ,70 ,71, 71 ,75 ,76 ,77 ,77, 78, 79 ,80, 82 ,82 ,85, 86 ,88 ,90 ,96, 97, 97};
    temp=sizeof(arr)/sizeof(int);
    // temp=50;
    let=temp;
    printf("长度为：%d\n",temp);
    printf("请输入一个整数：\n");
    scanf("%d",&a);
    for (int i = 0; i<let; i++)
    {
        temp=(temp-1+i)/2;
        if (arr[temp]!=a)
        {
            if(a<=arr[temp-1]){
                if (arr[temp-1]==a)
                {
                    printf("找到了,%d的下表为:%d\n",arr[temp-1],temp-1);
                    return 0;
                }
            }else if(a>=arr[temp+1]){
                if (arr[temp+1]==a)
                {
                    printf("找到了,%d的下表为:%d\n",arr[temp+1],temp+1);
                    return 0;
                }
            }
        }else if(a == arr[temp]){
            printf("找到了：下表为%d\n",temp);
            return 0;
        } 
    }
    printf("未找到\n");
    return 0;
}
