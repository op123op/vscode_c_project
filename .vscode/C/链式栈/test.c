#include <stdio.h>
#include "list.h"
int main(int argc, char const *argv[])
{
    P_Node stack = init(NULL);//头指针
    Data_Type data;
    for (int i = 0; i < 5; i++)
    {
        sprintf(data.name,"数学%d",i);
        data.Pice=4.2+i;
        data.id=i;
        P_Node p = init(&data);
        push_stack(stack,p);
    }
    P_Node node = NULL;
    for (int i = 0; i < 6; i++)
    {
        node = pull_stack(stack);
        if(node == NULL){
            break;
        }
        printf("%d,%s,%.2f\n",node->data.id,node->data.name,node->data.Pice);
    }
    return 0;
}
 