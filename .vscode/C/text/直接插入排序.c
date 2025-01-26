#include <stdio.h>
//插入排序(升序
void insertSort(int* arr, int lenght)
{
	for (int i = 1; i < lenght; i++)
	{
		int end = i - 1;
		int tmp = arr[i];
		//将tmp插入到[0,end]这个有序表的区间里
 
		while (end >= 0)
		{
			if (tmp < arr[end])  //如果tmp小于比对元素,将比对元素向后挪
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else       //如果tmp不小于比对元素,将tmp插入到比对元素后面
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}
int main(int argc, char const *argv[])
{
    int arr[] = {53,07,52,01,98,10,87,25,63,46};
    int lenght = sizeof(arr)/sizeof(int);
    insertSort(arr,lenght);
    printf("排序后：");
    for (int i = 0; i < lenght; i++)
    {
        printf("%d ",arr[i]);
    }
    puts("");
    return 0;
}
