
#include <stdio.h>
#include <stdarg.h>

int k = 1;

int run(int a,int b){
    printf("我被执行了%d%d\n",a,b);
    return 0;
}

void myfuntion(int num,...){
    va_list args;
    va_start(args,num);
    int a ;
    a = va_arg(args,int);
    printf("2:%d\n",a);
    a = va_arg(args,int);
    printf("3:%d\n",a);
    a = va_arg(args,int);
    printf("4:%d\n",a);

    va_end(args);
}

int main() {
    int arr[5] = {1,2,3,4,5} ;
    int a = 1;
    char b = 'b';
    int (*p)[5] = &arr ;
    int *p1 = &a;
    int **p2 = &p1;
    int (*p3)(int,int) = run;
    p3(1,1);
    a++;
    printf("a:%d\n",*(*p2));
    printf("arr:%p\n" , &arr );
    printf("%p\n",p3);
    printf("%p‐‐‐%d\n" ,p , (*p)[2] ); // 3 * p ==> arr
    printf("%p‐‐‐%d\n" , p+1 , (*(p+1))[2] ); // 已经越界访问

    printf("%d\n",1[arr]);
    printf("%p\n", &"Hello Even" ) ; 
    printf("%p\n", "Hello Even" ) ; 
    printf("123:%4d,%5.1f\n",123,123.56);
    printf("%p\n",(int*)(&arr[5]-&a));
    printf("--------\n");
    
    myfuntion(1,2,3,4);
    printf("funtion pointer:%ld\n",sizeof(p3));
    while (1)
    {
        /* code */
    }
    
    return 0;
}