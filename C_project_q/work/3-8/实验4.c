#include "stdio.h"         	// 库函数头文件一般用<>
main{}						// 这里main函数没有返回值类型，这里不是用花括号用括号，一般main函数用int或void作为返回值类型。
(							// 不是用括号作为代码块，而是用花括号
float g; h;					//	声明多个同类型的变量用逗号隔开
float tax, rate;			// 未初始化
g = e21;					//  赋值了一个未定义的标识符
tax = rate * g;				// 用未初始化和错误的值进行计算
printf("%f\n", tax);		// 前面报错，不会执行
)