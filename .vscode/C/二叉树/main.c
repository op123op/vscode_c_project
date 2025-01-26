#include <stdio.h>
#include <stdlib.h>
#include "./lib.h"
#include <string.h>

int main(int argc, char const *argv[])
{
    int arr[7] = {36,60,35,40,90,70,81};
    int length = sizeof(arr)/sizeof(int);
    printf("%d\n",length);
    //创建根指针
    P_Tree root = new_Tree_init(50);
    P_Tree new_node = NULL;
    for (int i = 0; i < length; i++)
    {
        new_node = new_Tree_init(arr[i]);
        insert(root,new_node);
    }
    display(root);
    //root_display(root);
    //int p = get_usr_input("请输入要删除的数据：");
    //del_tree(root,p);//删除二叉树节点
    //root_display(root);
    //display(root);//先序遍历
    //des_tree(root);//销毁二叉树
    display_layer(root);
    puts("");    
    return 0;
}
