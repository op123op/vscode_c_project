typedef int data_type;
//设计节点
typedef struct node{
    data_type data;//数据域
    struct node * next;//指针域
}Node,* P_Node;
//初始化
P_Node new_head_node(int new_data);
//头插
int add_head_node(P_Node head,P_Node new_node);
//尾插
int add_tail_node(P_Node head,P_Node new_node);
//查找节点，第二个参数为NULL时仅遍历节点
Node * display_list(P_Node head,int *data);
//删除
Node * del_list(P_Node head,int  data);
//移动
int move_node(Node *head,data_type data,data_type tag_data);