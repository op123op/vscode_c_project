#include <stdio.h>
#include <stdlib.h>

// 合并两个有序数组的函数
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // 左数组的大小
    int n2 = r - m;     // 右数组的大小

    // 创建临时数组
    int L[n1], R[n2];

    // 复制数据到临时数组L[] 和 R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 合并临时数组回到arr[l..r]中
    int i = 0; // 左数组的初始索引
    int j = 0; // 右数组的初始索引
    int k = l; // 合并后数组的初始索引

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制左数组中的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 复制右数组中的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 递归地将数组分成两半，然后调用merge函数
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // 找到中间索引
        int m = l + (r - l) / 2;

        // 分别对左右两半进行排序
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // 合并已排序的两半
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {53, 7, 52, 1, 98, 10, 87, 25, 63, 46};
    int lenght = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, lenght - 1);
    printf("排序后：");
    for (int i = 0; i < lenght; i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}