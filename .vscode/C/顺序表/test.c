#include <stdio.h>
#include <string.h>
#include "sqlist.h"
#include <stdlib.h>
int main(){
    int i=0,r=0;
    P_data p=data_init();
    for ( i = 0; i < 10; i++)
    {
        printf("请输入你要插入的值：");
        scanf("%d",&r);
        while (getchar()!='\n')
        {
            /* code */
        }
        
        data_insert_sort(p,r);
    }
    data_printf(p);
    free(p->data_type1);
    free(p);
    
    return 0;
}