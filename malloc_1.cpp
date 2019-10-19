// 使用malloc函数实现动态内存分配和释放 :模拟数组 

# include <stdio.h>
# include <malloc.h>

int main(void)
{
	int a[5] = {1,2,3,4,5};
	
	int len = 5;
	printf("请输入你想创建的数组长度：len=");
	scanf("%d",&len); // 这里必须写上&，代表赋值给这个地址的变量。不写程序会爆炸 

	int * p_a = (int *)malloc(sizeof(int)*len);
	// 这里创建了一个大小为4*len的一个连续空间，本来没有类型，所以需要强制转换成int *类型
	// 因为我们想构造一个类似数组的东西，而数组的变量名代表的是第一项的地址，所以本身的类型是指针类型，所以这里是int *
	// 经过这样的创建之后，我们处理p_a，就可以像处理数组的头指针一样处理，那么*p_a就是头部元素的值了 
	 
	// 给创建的新数组赋值：
	printf("请按顺序输入数组的每一个值（每一个值后回车）：\n");
	for (int i=0; i<len; i++)
		scanf("%d",&p_a[i]); // p_a就相当于一个数组，所以可以直接用p_a[i]来访问第i项 
	
	printf("你创建的数组为：\n"); 
	for (int i=0; i<len; i++)
		printf("%d ",*(p_a+i));  // p_a+i代表的是第i项的地址，所以前面需要加*。这里也可以直接使用p_a[i] 
	
	// 通过malloc创建的空间，必须手动通过free释放 
	free(p_a);
	printf("\n内存释放后：");
	for (int i=0; i<len; i++)
		printf("%d ",*(p_a+i));
	
		
	return 0;
 } 
