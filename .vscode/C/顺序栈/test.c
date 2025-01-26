#include <stdio.h>
#include <stdlib.h>

typedef int Data_type;
typedef struct stack{
    Data_type *data;//数据的地址
    int size;       //数据总大小大小
    int top;        //顺序栈栈顶偏移量
}Stack,*P_Stack;
Stack init(int size){//初始化
    Stack M_stack;
    M_stack.data=calloc(size,sizeof(Data_type));
    M_stack.size=size;
    M_stack.top=0;
    return M_stack;
}
Stack push_stack(Stack stack,Data_type num){//入栈
    if(stack.top >= stack.size){
        printf("栈已经满了\n");
        return stack;
    }
    stack.data[stack.top]=num;
    stack.top++;
    return stack;
}
Stack pull_stack(Stack stack){//出栈
    if(stack.top <=0){
        printf("栈为空\n");
        return stack;
    }
    stack.top--;
    return stack;
}
int display(Stack stack){
    if(stack.data == NULL || stack.top == 0){
        printf("栈为空！\n");
        return -1;
    }
    for (int i = 0; i < stack.top ; i++)
    {
        printf("i:%d,data:%d\n",i,stack.data[i]);
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    Stack ptr = init(10);
    printf("入栈\n");
    for (int i = 0; i < 10; i++)
    {
        ptr=push_stack(ptr,i);
    }
    display(ptr);
    printf("出栈\n");
    for (int i = 0; i < 10; i++)
    {
        ptr=pull_stack(ptr);
    }
    display(ptr);
    free(ptr.data);
    return 0;
}
