// 指针的基本概念 

# include <stdio.h>

int main(void)
{
	int i = 10;
	int * p; // p是个变量名字，int * 表示该p变量只能存储in同类型变量的地址 
	p = &i; // 把i的地址给p，那么p指针实际上就指向了i变量 
	// 上面两行等价于 int * p = &i;
	
	int j;
	j = *p; // 等价于j = i.  *p代表p指针所对应的变量。
	// 但注意，这里只是把值赋给了j，i的改变对j无影响，而对*p有影响 
	
	printf("i = %d, j = %d, *p = %d\n", i, j, *p);
	// 输出： i = 10, j = 10, *p = 10
	
	i = 100;
	printf("i = %d, j = %d, *p = %d", i, j, *p);
	// 输出： i = 100, j = 10, *p = 100
	return 0;
}
