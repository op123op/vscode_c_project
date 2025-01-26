#include <stdio.h>
#include "./lib.h"
#include <stdlib.h>

//初始化节点
P_Tree new_Tree_init(data_type data){
    P_Tree new_node = calloc(1,sizeof(Tree));
    new_node->data = data;
    new_node->L = new_node->R = NULL;
    return new_node;
}

//插入树节点
P_Tree insert(P_Tree root,P_Tree new_node){
    if (root == NULL)
    {
        return new_node;
    }
    if (root->data < new_node->data)
    {
        root->R = insert(root->R,new_node);
    }else{
        root->L = insert(root->L,new_node);
    }
    return root;
}

//二叉树中序遍历显示
void display(P_Tree root){
    if (root == NULL)
    {
        return ;
    }
    display(root->L);
    printf("%d\t",root->data);
    display(root->R);
    return ;
}

//二叉树先序遍历显示
void root_display(P_Tree root){
    if (root == NULL)
    {
        return ;
    }
    printf("%d\t",root->data);
    display(root->L);   
    display(root->R);
    return ;
}

//删除树节点
P_Tree del_tree(P_Tree root,data_type data){
    if (root == NULL)
    {
        return NULL;
    }
    P_Tree temp = NULL;
    if (data < root->data)
    {
        root->L = del_tree(root->L,data);
    }else if (data > root->data)
    {
        root->R = del_tree(root->R,data);
    }else{
        printf("要删除的数据：%d\n",root->data);
        if (root->L == NULL && root->R == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }else if (root->L != NULL)
        {
            for (temp = root->L; temp->R != NULL; temp = temp->R);
            root->data = temp->data;
            root->L = del_tree(root->L,temp->data);
        }else
        {
            for (temp = root->R; temp->L != NULL; temp = temp->L);
            root->data = temp->data;
            root->R = del_tree(root->R,temp->data);
        }
    }
    return root;
}

//树的销毁
void des_tree(P_Tree root){
    if (root == NULL)
    {
        return ;
    }
    des_tree(root->L);
    des_tree(root->R);
    printf("free:%d ",root->data);
    free(root);
    root = NULL;
}

//初始化新建队列节点
P_List new_list_init(P_Tree root){
    P_List new = calloc(1,sizeof(List));
    new->tree = root;
    new->next = new;
    return new;
}

//入队
void list_enqueue(P_List list,P_Tree root){
    if (root == NULL)
    {
        printf("队列为空！！\n");
        return ;
    }
    P_List tmp = list;
    P_List new = new_list_init(root);
    for(; tmp->next !=list; tmp = tmp->next);
    new->next = tmp->next;
    tmp->next = new;
    return ;
}

//出队
int list_dequeue(P_List list){
    if (list->next == list)
    {
        return 0;
    }
    P_List tmp = list->next;
    if (tmp->tree->L != NULL)
    {
        list_enqueue(list,tmp->tree->L);
    }
    if (tmp->tree->R != NULL)
    {
        list_enqueue(list,tmp->tree->R);
    }
    printf("%d ",tmp->tree->data);
    list->next = tmp->next;
    tmp->next = tmp;
    free(tmp);
    tmp = NULL;
    return 1;
}

//按层遍历
void display_layer(P_Tree root){
    P_List list = new_list_init(NULL);
    list_enqueue(list,root);
    printf("\n----按层遍历----\n");
    while (list_dequeue(list));
}

//用户输入
int get_usr_input(char * msg ){
    printf("%s\n" , msg);

    int num = 0 ;
    int ret_val = 0 ;

    while(ret_val != 1 )
    {
        ret_val = scanf("%d" , &num) ;
        if (ret_val != 1 )
        {
            while(getchar() != '\n');
            continue ;
        }
    }

    return num ;

}