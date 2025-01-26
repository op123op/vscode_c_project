#include <stdio.h>

// 获取数组中最大元素的函数
int getMax(int arr[], int lenght) {
    int max = arr[0];
    for (int i = 1; i < lenght; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 计数排序的辅助函数
void countSort(int arr[], int lenght, int exp) {
    int output[lenght]; // 临时数组，用于存放排序后的结果
    int i, count[10] = {0}; // 计数数组，初始化为0

    // 计算每个数字出现的次数
    for (i = 0; i < lenght; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 将count数组中的每个数字转化为实际位置
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 构建输出数组
    for (i = lenght - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将排序后的数据复制回原数组
    for (i = 0; i < lenght; i++) {
        arr[i] = output[i];
    }
}

// 基数排序函数
void radixSort(int arr[], int lenght) {
    int max = getMax(arr, lenght); // 找到最大元素，确定最大位数
    int exp; // 指数，表示当前排序的位数

    // 对每一位进行排序
    for (exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, lenght, exp); // 对每一位进行计数排序
    }
}

int main() {
    int arr[] = {53, 7, 52, 1, 98, 10, 87, 25, 63, 46};
    int lenght = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, lenght);
    printf("排序后：");
    for (int i = 0; i < lenght; i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}