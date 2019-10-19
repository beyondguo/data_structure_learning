// 如何修改指针变量的值
 
# include <stdio.h>

void f(double ** p);

int main(void)
{
	double *p;
	double x = 66.6;
	p = &x; // x占8字节（本机是16位？），1字节一个地址，1字节8位 。p存放的是x的第一个字节的地址
	printf("%p\n",p);
	
	// 修改变量p的值：
	// 凡是想通过外部函数修改变量的值，必须传入变量的地址，这里就是&p，
	// 而本身p也是一个地址，所以函数的形参的类型应该是double **类型 
	f(&p); 
	printf("%p",p);
	
	return 0;
}

void f(double ** p)
{
	*p = (double *)0x000000000024FE44;
}
