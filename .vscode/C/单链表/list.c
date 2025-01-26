#include <stdio.h>
#include <stdlib.h>

typedef     int     Data_Type ;

// 节点设计
typedef struct list
{
    Data_Type Num ;   //数据
    struct list * Next ; // 后继指针
}List , *P_List;

P_List init_new_node(Data_Type new_data)
{
    // 申请一个头节点
    List * head = calloc(1,sizeof(List) );

    head->Num = new_data ; 
    head->Next = NULL ; // 初始化后继指针指向空

    return head ;
}

int add_2_list_tail(P_List head , P_List new_node)
{
    if( head == NULL )
    {
        printf("链表头异常！！！\n");
        return -1 ;
    }

    //遍历找到链表的末尾
    P_List tmp ;
    // while(tmp->Next != NULL )
    // {
    //     tmp = tmp->Next;
    // }
    //     初始化            判断只要tmp->next==NULL 则表示到达末尾节点 
    for ( tmp = head ; tmp->Next != NULL ; tmp = tmp->Next);

    //1 让新节点的后继指针指向头结点的后记节点
    new_node->Next = tmp->Next ;

    //2 让头节点的后继指针指向新节点
    tmp->Next = new_node ;

    
    return 0 ;

}


int add_2_list_head(P_List head , P_List new_node)
{
    if( head == NULL )
    {
        printf("链表头异常！！！\n");
        return -1 ;
    }

    //1 让新节点的后继指针指向头结点的后记节点
    new_node->Next = head->Next ;

    //2 让头节点的后继指针指向新节点
    head->Next = new_node ;

    return 0 ;
}

List * list_4_each(List * head , Data_Type * Num)
{
    if(head->Next == NULL )
    {
        printf("该表为空！！！！\n");
        return NULL ;
    }

    List * tmp = head ; // 把头结点的NEXT （第一个数据）

    while( tmp->Next != NULL ) // 只要tmp 不等于NULL 就循环
    {
        if(Num == NULL )
        {
            printf("data:%d\n" , tmp->Next->Num);
        }
        else
        {
            if(tmp->Next->Num == *Num)
            {
                return tmp ;
            }
        }
        tmp = tmp->Next ; // tmp 往后走一个
    }
    
    return NULL  ;
}

List * del_4_list( List * head , Data_Type del_num)
{
    if( head->Next == NULL )
    {
        printf("该表已空！！\n");
        return NULL  ;
    }

    // 遍历查找需要移除的节点
    List * tmp = list_4_each(head , &del_num ); // 需要删除的前一个
    if(tmp == NULL )
    {
        printf("没有你要的豆腐！！\n");
        return NULL ;
    }
    List * del = tmp->Next ; // 需要删除的节点

    // 把找到的节点从链表中剔除
    tmp->Next = del->Next ;  // 让需要删除节点的前一个节点的后继指针指向需要删除节点的后继节点
    del->Next = NULL ; // 让del 的next不要再指向链表，而是指向空

    return del ;
}


int main(int argc, char const *argv[])
{
    // 初始化链表头
    List * head = init_new_node( 998 );
    

    for (size_t i = 1; i < 11; i++)
    {
         // 创建新节点
        List * new_node = init_new_node( i );
        //插入数据
        add_2_list_tail(head , new_node );
    }
    list_4_each(head , NULL );


    // 从链表中剔除节点
    List * del = del_4_list(head , 10);
    printf("%p:%d\n" , del , del->Num );
    free(del);
    del = NULL ;


    // 显示链表
    list_4_each(head , NULL );
    
   




    return 0;
}
