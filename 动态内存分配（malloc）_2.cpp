// 跨函数分配内存问题
# include <stdio.h>
# include <malloc.h>

void f1(int *p);
void f2(int ** p);
void f3(int ** p);
int main(void)
{
	int * p;
// //会让程序崩溃，因为函数无法给p赋值，因为你传入的不是地址！所以打印的时候根本无从打印 
//	f1(p);  
//	printf("%d",*p);
	
	f2(&p); // 要想通过函数给p赋值，必须传入p的地址 
	printf("p的值和地址：\n");
	printf("%d\n",*p);
	printf("%p\n",p);
	printf("看看能否对p所指向的空间进行操作：\n");
	*p = *p + 1;
	printf("%d\n",*p); // 发现确实可以操作啊，那说明确确实实给p分配了内存啊！ 
// 输出： 
//s的值和地址：
//0
//000000000024FE0C
//p的值和地址：
//0
//000000000024FE0C

	f3(&p); // 要想通过函数给p赋值，必须传入p的地址 
	printf("p的值和地址：\n");
	printf("%d\n",*p);
	printf("%p\n",p);
}


void f1(int * p)
{
	int s;
	p = &s;
}

// 奇怪了，按照 郝斌老师的讲法，下面的函数，只是在函数内把s的地址给到了p的地址上，但是函数结束后s就没了，所以p也没有赋值成功
// 但我自己运行的结果没问题，p的值还是可以打印出来 
void f2(int ** p)
{
	int s;
	printf("s的值和地址：\n");
	printf("%d\n",s);
	printf("%p\n",&s);
	*p = &s;
} 

void f3(int ** p)
{
	*p = (int *)malloc(4);
} 
