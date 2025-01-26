#include <stdio.h>
#include "sqlist.h"
#include <stdlib.h>

P_data data_init(){
    P_data p=calloc(1,sizeof(sqlist_data));
    p->data_type1=calloc(DATA_SIZE,sizeof(data_type));
    p->Size=DATA_SIZE;
    p->Last=0;
    return p;
}
int data_insert(P_data ptr,data_type new_data){
    if(ptr==NULL||ptr->Last==ptr->Size){
        printf("内存已满\n");
        return ptr->Last;
    }
    ptr->data_type1[ptr->Last]=new_data;//等价于ptr->*(data_type1+(ptr->Last))=new_data;
    ptr->Last++;
    return ptr->Last;
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
int data_insert_sort(P_data p,data_type new_data1){
    int i=0;
    if(p->data_type1==NULL||p->Last>=p->Size){
        printf("内存已满\n");
        return p->Last;
    }
    // p->data_type1[p->Last]=new_data1;
    // p->Last++;
    int temp=0;
    if(!(p->Last==0)){
        for ( i = 0; i < p->Last; i++)
        {
            if(new_data1 < p->data_type1[i]){
                temp=i;
                for (int j = 0; j < p->Last-temp; j++)
                {
                    p->data_type1[p->Last-j]=p->data_type1[p->Last-j-1];
                }
                p->data_type1[temp]=new_data1;
                p->Last++;
                return 0;
            }
        }
    }
    p->data_type1[p->Last]=new_data1;
    p->Last++;
    
    return p->Last;
    
}