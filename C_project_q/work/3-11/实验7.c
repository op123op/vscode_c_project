// a) 一个有10个指针的数组，该指针是指向一个整型数的;
// b) 一个指向有10个整型数数组的指针 ;
// c) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数;
// d) 一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数;


a) int *a[10]
b) int (*a)[10]
c) int (*a) (int)
d) int *a[10] (int)