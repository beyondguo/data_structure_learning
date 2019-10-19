# include <stdio.h>

void Change_Array(int *p)
{
	p[0] = -1; // p[0] == a[0]
}

void Show_Array(int * p, int len)
{
	int i;
	for (i=0; i<len; i++) printf("%d ",p[i]);
}
int main(void)
{
	int a[5] = {1,2,3,4,5};
	// 一维数组名是一个指针常量，
	// 它存放的是一维数组第一个元素的地址
	// 它的值不能被改变，一维数组名指向的是第一个元素
	
	a[3] == *(a+3); // a[i]是直接取出第i项的值 
	printf("%d\n",*a); 
	printf("%p\n",a); // %p代表以16进制输出 
	printf("%p\n",a+1); // a+i，代表a所代表的数组的第i项的 地 址 ！ 
	printf("%p\n",a+2);
	printf("%p\n",a+3);
	
	Change_Array(a);
	Show_Array(a,5); // a就是int *类型 
	
}
