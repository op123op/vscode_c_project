typedef struct data
{
    char name[20];
    float Pice;
    int id;
}Data_Type;
typedef struct list{
    Data_Type data;
    struct list * next;
}Node,* P_Node;
P_Node init(Data_Type *new_data);//初始化
int push_stack(P_Node stack,P_Node Node);//入栈
Node * pull_stack(P_Node stack);//出栈
