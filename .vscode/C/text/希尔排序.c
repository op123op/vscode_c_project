#include <stdio.h>

// 希尔排序函数，arr是要排序的数组，n是数组的长度
void shellSort(int arr[], int lenght) {
    // 初始化增量序列
    int gap = lenght / 2;
    
    // 使用增量序列进行希尔排序
    while (gap > 0) {
        // 从第gap个元素开始，对数组进行直接插入排序
        for (int i = gap; i < lenght; i++) {
            // 记录需要插入的元素
            int temp = arr[i];
            int j;
            
            // 在arr[i-gap]和arr[i]之间找到temp的正确位置
            for (j = i; (j >= gap) && (arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // 将temp插入到正确的位置
            arr[j] = temp;
        }
        
        // 减小增量
        gap = gap / 2;
    }
}
int main() {
    int arr[] = {53, 7, 52, 1, 98, 10, 87, 25, 63, 46};
    int lenght = sizeof(arr) / sizeof(arr[0]); 
    shellSort(arr, lenght);
    // 打印排序后的数组
    printf("排序后：");
    for (int i = 0; i < lenght; i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}