#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef int Date_type;
typedef struct queue{
    Date_type *data;
    int size;
    int front;
    int rear;
}Node,*P_Node;
P_Node init(int Size){
    P_Node manager = calloc(1,sizeof(Node));
    if (manager == NULL)
    {
        printf("申请空间失败\n");
    }else{
        manager->data = calloc(Size,sizeof(int));
        manager->front = manager->rear = 0;
        manager->size = Size;
    }
    return manager;
}
int enqueue(P_Node manager,int data){//入队
    if (manager->data == NULL || manager->front == (manager->rear+1)%manager->size)
    {
        printf("队列异常,可能是满了\n");
        return -1;
    }
    manager->data[manager->rear] = data;
    manager->rear = (manager->rear+1)%manager->size;
    return 0;
}
int dequeue(P_Node manger){//出队
    if (manger->data == NULL || manger->front == manger->rear)
    {
        printf("队列为空\n");
        return -1;
    }
    Date_type tmp = manger->data[manger->front];
    manger->data[manger->front] = 0;
    manger->front = (manger->front+1)%manger->size;
    return tmp;
}
int display(P_Node manger){
    if (manger->data == NULL || manger->front == manger->rear)
    {
        printf("队列为空\n");
        return -1;
    }
    int m = 1;
    for (int i = manger->front; i != manger->rear; i = (i+1)%manger->size)
    {
        printf("当前任务%d：%d ",m++,manger->data[i]);
    }
    puts("");
    return 0;
}
int main(int argc, char const *argv[])
{
    P_Node manager = init(SIZE);
    if (manager == NULL)
    {
        return 0;
    }
    for (int i = 0; i < 9; i++)
    {
        enqueue(manager,i);
    }
    display(manager);
    for (int i = 0; i < 5; i++)
    {
        dequeue(manager);
    }
    display(manager);
    for (int i = 8; i < 14; i++)
    {
        enqueue(manager,i);
    }
    display(manager);
    free(manager->data);
    free(manager);
    return 0;
}
