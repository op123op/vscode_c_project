#include <stdlib.h>
#include <stdio.h>
#include "sl_list.h"
int main(int argc, char const *argv[])
{
    Node *head=new_head_node(0);
    for (int i = 1; i <= 10; i++)
    {
        Node * p=new_head_node(i);
        add_tail_node(head,p);
    }
    Node *del=del_list(head,10);
    free(del);
    del=NULL;
    move_node(head,2,6);
    display_list(head,NULL);
    free(head);
    head=NULL;
    return 0;
}
