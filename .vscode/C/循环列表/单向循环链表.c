#include <stdio.h>
#include <stdlib.h>
typedef int Data_type;
typedef struct node{
    Data_type data;
    struct node * next;
}Node,*P_Node;
P_Node new_node(Data_type data){
    P_Node p=calloc(1,sizeof(Node));
    (*p).data=data;
    p->next=p;
    return p;
}
int head_insert(P_Node head,P_Node node){
    if(head==NULL||node==NULL){
        printf("插入异常\n");
        return -1;
    }
    node->next=head->next;
    head->next=node;
    return 0;
}
int display(P_Node head){
    if(head==NULL||head->next==head){
        printf("链表为空");
        return -1;
    }
    for (P_Node temp=head->next; temp!=head ; temp=temp->next)
    {
        printf("data:%d\n",temp->data);
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    P_Node head=new_node(0);//头节点
    P_Node node=NULL;
    for (int i = 1; i < 11; i++)
    {
        node=new_node(i);
        head_insert(head,node);
    }
    
    display(head);
    free(head);
    head=NULL;
    return 0;
}
