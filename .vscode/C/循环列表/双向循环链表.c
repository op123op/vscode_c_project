#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define Left true
#define Right false
typedef int Date_Type;
typedef struct node{
    Date_Type data;
    struct node * prev,* next;//前驱指针,后继指针
}Node,*P_Node;
P_Node new_node(Date_Type data){//新建节点
    P_Node new = calloc(1,sizeof(Node));
    new->data = data;
    new->prev = new;
    new->next = new;
    return new;
}
bool head_insert(P_Node head,P_Node new){//头插
    if(head == NULL || new == NULL){
        printf("链表为空\n");
        return false;
    }
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
    return true;
}
bool tail_insert(P_Node head,P_Node new){//尾插
    if(head == NULL || new == NULL){
        printf("链表为空\n");
        return false;
    }
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
    return true;
}
bool display(P_Node head,bool R_L){//显示R_L参数指定向左还是向右显示
    if(head == NULL || head->next == head){
        printf("链表为空\n");
        return false;
    }
    P_Node tmp = NULL;
    if(R_L){
        tmp = head->prev; 
    }else{
        tmp = head->next;
    }
    while (tmp!=head)
    {
        if(R_L){
            printf("data:%d ",tmp->data);
            tmp = tmp->prev;
        }else{
            printf("data:%d ",tmp->data);
            tmp = tmp->next;
        }
    }
    puts("");
    return true;
}
P_Node find_node(P_Node head,Date_Type data){//查找节点
    if(head == NULL || head->next == head){
        printf("链表为空\n");
        return NULL;
    }
    P_Node tmp = head->next;
    for ( ; tmp != head; tmp = tmp->next)
    {
        if(tmp->data == data){
            return tmp;
        }
    }
    return NULL;
}
P_Node del_node(P_Node head,Date_Type data){//删除节点
    if(head == NULL || head->next == head){
        printf("链表为空\n");
        return NULL;
    }
    P_Node tmp = find_node(head,data);
    if(tmp == NULL){
        return NULL;
    }
    tmp->next->prev = tmp->prev;
    tmp->prev->next = tmp->next;
    tmp->prev = tmp;
    tmp->next = tmp;
    return tmp;
}
bool mv_node(P_Node head,Date_Type data_mv,Date_Type data_tag){//移动
    if(head == NULL || head->next == head){
        printf("链表为空\n");
        return false;
    }
    P_Node tmp = del_node(head,data_mv);
    if(tmp == NULL){
        return false;
    }
    P_Node tmp1 = find_node(head,data_tag);
    if(tmp1 == NULL){
        return false;
    }
    head_insert(tmp1,tmp);
    return true;
}
bool insert_sort(P_Node head,Date_Type new_data){//插入排序
    if(head->next == head){
        P_Node new = new_node(new_data);
        head_insert(head,new);
        return true;
    }
    P_Node tmp = head->next;
    P_Node new = NULL;
    P_Node temp = NULL;
    for ( ; tmp!=head ; tmp = tmp->next)
    {
        if (new_data >= tmp->data)
        {   
            temp = tmp;
        }else{
            new = new_node(new_data);
            temp = tmp->prev;
            head_insert(temp,new);
            return true;
        }
    }
    new = new_node(new_data);
    head_insert(temp,new);
    return true;
}
int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    P_Node head = new_node(0);
    P_Node new = NULL;    
    for (int i = 0; i < 10; i++)
    {
        int rond = rand()%10;
        printf("rond:%d ",rond);
        // new = new_node(rond);
        // if(new == NULL){
        //     printf("新建节点失败！\n");
        //     return 0;
        // }
        // head_insert(head,new);//头插
        // tail_insert(head,new);//尾插
        insert_sort(head,rond);
    }
    puts("");
    P_Node fid = find_node(head,5);
    if(fid == NULL){
        printf("节点没有找到;\n");
    }else{
        printf("%p:%d\n",fid,fid->data);
    }
    printf("移动前:");
    if(!display(head,Right)){
        printf("显示失败\n");
    }
    fid = del_node(head,5);
    if(fid == NULL){
        printf("删除失败\n");
    }
    if(!mv_node(head,4,0)){
        printf("移动失败\n");
    }
    printf("移动并删除5后:");
    if(!display(head,Left)){
        printf("显示失败\n");
    }
    return 0;
}
