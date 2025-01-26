#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>

Node * init(Data_Type *new_data){
    P_Node ptr = calloc(1,sizeof(Node));
    if( new_data != NULL){
        strcpy(ptr->data.name,new_data->name);
        ptr->data.id=new_data->id;
        ptr->data.Pice=new_data->Pice;
    } 
    ptr->next=NULL;
    return ptr;
}
int push_stack(P_Node stack,P_Node Node){
    if( stack == NULL || Node == NULL){
        return -1;
    }
    Node->next = stack->next;
    stack->next = Node;
    return 0;
}
Node * pull_stack(P_Node stack){
    if(stack->next == NULL){
        printf("栈为空;");
        return NULL;
    }
    P_Node temp = stack->next;
    stack->next = temp->next;
    temp->next = NULL;
    return temp;
}