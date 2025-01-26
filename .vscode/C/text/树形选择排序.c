#include <stdio.h>

void selectionSort(int arr[], int lenght) {
    int i, j, min_index, temp;
    // 遍历数组中的所有元素
    for (i = 0; i < lenght - 1; i++) {
        // 找到未排序部分的最小元素的索引
        min_index = i;
        for (j = i + 1; j < lenght; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // 将找到的最小元素与第i个元素交换
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {26, 37, 8, 63, 12, 59, 12, 48};
    int lenght = sizeof(arr) / sizeof(arr[0]);//数组长度
    selectionSort(arr, lenght);
    printf("排序后: ");
    for (int i = 0; i < lenght; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}