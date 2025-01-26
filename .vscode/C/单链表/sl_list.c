#include <stdio.h>
#include <stdlib.h>
#include "sl_list.h"

Node * new_head_node(int new_data){
    Node * head=calloc(1,sizeof(Node));
    head->data=new_data;
    head->next=NULL;
    return head;
}
//头插
int add_head_node(P_Node head,P_Node new_node){
    if(head==NULL){
        printf("链表异常");
        return -1;
    }
    new_node->next=head->next;//让新节点指向头节点的后继
    head->next=new_node;//头节点指向新节点
    return 0;
}
//尾插
int add_tail_node(P_Node head,P_Node new_node){
    if(head==NULL){
        printf("链表异常");
        return -1;
    }
    P_Node temp;
    // while (temp->next!=NULL)
    // {
    //     temp=temp->next;
    // }
    for (temp=head;temp->next!=NULL; temp=temp->next);//循环遍历找到尾节点  temp=temp->next(指针往后移)
    new_node->next=temp->next;
    temp->next=new_node;
    return 0;
    
}
//查找节点，第二个参数为NULL时仅遍历节点
Node * display_list(P_Node head,data_type *data){
    if(head->next==NULL){
        printf("链表为空");
        return NULL;
    }
    P_Node temp;
    for (temp=head; temp->next!=NULL; temp=temp->next)
    {
        if(data==NULL){
            printf("data:%d ",temp->next->data);
        }else{
            if(temp->next->data==*data){
                return temp;//删除节点的前一个结点
            }
        }
    }
    return NULL;
}
//删除
Node * del_list(Node * head,data_type  data){
    if(head->next==NULL){
        printf("链表为空");
        return NULL;
    }
    Node * tmp=display_list(head,&data);//删除的前一个节点
    if(tmp == NULL )
    {
        printf("没有你要的豆腐！！\n");
        return NULL ;
    }
    Node * del=tmp->next;//要删除的节点
    tmp->next=del->next;
    del->next=NULL;
    return del;
}
//移动
int move_node(Node *head,data_type data,data_type tag_data){
    if(head->next==NULL){
        printf("链表为空");
        return -1;
    }
    Node *tmp=del_list(head,data);
    Node *tag=display_list(head,&tag_data);
    add_head_node(tag->next,tmp);
    return 0;
}