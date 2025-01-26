#ifndef _LIB_H1_
#define _LIB_H1_

typedef int data_type;
//树结构体
typedef struct tree{
    data_type data;
    struct tree *L,*R;
}Tree,*P_Tree;
//队列
typedef struct list{
    P_Tree tree;
    struct list *next;
}List,*P_List;
P_Tree new_Tree_init(data_type data);       //初始化新建树节点
P_Tree insert(P_Tree root,P_Tree new_node); //插入树节点
void display(P_Tree root);                  //先序遍历
void root_display(P_Tree root);             //后序遍历
P_Tree del_tree(P_Tree root,data_type data);//删除树节点
int get_usr_input(char * msg );             //用户输入
void des_tree(P_Tree root);                 //销毁二叉树
P_List new_list_init(P_Tree root);          //初始化新建队列节点
void list_enqueue(P_List list,P_Tree root); //入队
int list_dequeue(P_List list);              //出队
void display_layer(P_Tree root);            //按层遍历
#endif