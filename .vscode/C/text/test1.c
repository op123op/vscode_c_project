#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DATA_SIZE 10 
typedef int data_type;  // 顺序表数据类型

typedef struct data {  // 管理结构体
    data_type *data_type1;  // 指向顺序表
    int Size;  // 顺序表的最大存储数
    int Last;  // 顺序表实际存储数
} sqlist_data, *P_data;

P_data data_init() {
    P_data p = calloc(1, sizeof(sqlist_data));
    p->data_type1 = calloc(DATA_SIZE, sizeof(data_type));
    p->Size = DATA_SIZE;
    p->Last = 0;
    return p;
}

int data_insert_sort(P_data p, data_type new_data1) {
    if (p->data_type1 == NULL || p->Last >= p->Size) {
        printf("内存已满\n");
        return p->Last;
    }

    int temp = 0;
    if (p->Last != 0) {
        for (int i = p->Last - 1; i >= 0; i--) {
            if (new_data1 < p->data_type1[i]) {
                p->data_type1[i + 1] = p->data_type1[i];
                temp = i;
            } else {
                break;
            }
        }
    }
    p->data_type1[temp] = new_data1;
    p->Last++;
    
    return p->Last;
}
int data_printf(P_data pt){
    int i=0;
    if(pt->data_type1==NULL){
        printf("顺序表为空！");
        return 0;
    }
    for ( i = 0; i < pt->Last; i++)
    {
        printf("data:%d ",pt->data_type1[i]);
    }
    return 1;
}
int main() {
    int i = 0, r = 0, o = 0;
    P_data p = data_init();
    for (i = 0; i < 10; i++) {
        printf("请输入你要插入的值：");
        scanf("%d", &r);
        
        data_insert_sort(p, r);
    }
    data_printf(p);
    
    return 0;
}
