#define DATA_SIZE 10 
typedef int data_type;//顺序表数据类型
typedef struct data{//管理结构体
    data_type *data_type1;//指向顺序表
    int Size;//顺序表的最大存储数
    int Last;//顺序表实际存储数
}sqlist_data,*P_data;
P_data data_init();
int data_insert(P_data ptr,data_type new_data);
int data_printf(P_data pt);
int data_insert_sort(P_data p,data_type new_data1);//按顺序插入数据