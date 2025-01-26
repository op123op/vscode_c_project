#include <stdio.h>

void swap(int *a,int *b){//交换两个数
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sqort(int *arr,int left,int right){//传入数组，数组下标最左和最右
    int left_init = left;//下标最左初始值
    int right_init = right;//下标最右初始值
    if(left >= right){//递归调用终止条件,
         return ;   
    }
    int key = left; //下标最左给key
    while (left < right)//如果left等于或大于right跳出
    {
        //右边选小
        while (arr[key] <= arr[right] && left < right)//left < right防止越界(万一key下标对应值是最小的)
        {//如果right下标对应值大于key的下标对应值就right向左移
            right--;
        }
        //左边选大
        while (arr[key] >= arr[left] && left < right)
        {//如果left下标对应值小于key的下标对应值就left向右移
            left++;
        }
        //小的和大的交换
        swap(&arr[left],&arr[right]);
    }
    swap(&arr[key],&arr[right]);//把key的下标对应值换到中间
    key = right;//key下标换到中间下标
    sqort(arr,left_init,key - 1);//递归调用使得key左边排序
    sqort(arr,key + 1,right_init);//递归调用使得key右边排序
}
int main(int argc, char const *argv[])
{
    int arr[8] = {26,37,8,63,12,59,12,48};
    int lenght = sizeof(arr)/sizeof(int);//数组长度
    sqort(arr,0,lenght-1);
    printf("排序后：");
    for (int i = 0; i < lenght; i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}
