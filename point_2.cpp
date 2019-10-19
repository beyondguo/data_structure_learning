// 通过指针操作来使用函数改变变量的值 

#include <stdio.h>

void f1(int i)
{
	i = 100;
} 

void f2(int *i) // 不是定义了一个名字叫*i的形参，而是定义了一个形参，该形参名字叫做i，类型是int *！ 
{
	*i = 100;
} 

int main(void){
	int i = 9;
	printf("i = %d\n",i);
	f1(i); 
	printf("i = %d\n",i);
	f2(&i);
	printf("i = %d",i);
}
