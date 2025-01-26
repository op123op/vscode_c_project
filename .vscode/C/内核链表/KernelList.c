#include <stdio.h>
#include "Kernel_List.h"

typedef int data_type;
struct list{
    struct list *prev,*next;
} ;
typedef struct node{
    data_type data;
    struct list ptr;
}Node ,*P_Node;

P_Node kernel_list_init(data_type data){
    P_Node head = calloc(1,sizeof(Node));
    head->data = data;
    INIT_LIST_HEAD(&head->ptr);
    return head;
}
int main(int argc, char const *argv[])
{
    P_Node head = kernel_list_init(0);
    P_Node new = NULL;
    for (int i = 0; i < 10; i++)  
    {
        new = kernel_list_init(i);
        list_add(&new->ptr,&head->ptr);
    }
    
    return 0;
}
