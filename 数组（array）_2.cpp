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
	// һά��������һ��ָ�볣����
	// ����ŵ���һά�����һ��Ԫ�صĵ�ַ
	// ����ֵ���ܱ��ı䣬һά������ָ����ǵ�һ��Ԫ��
	
	a[3] == *(a+3); // a[i]��ֱ��ȡ����i���ֵ 
	printf("%d\n",*a); 
	printf("%p\n",a); // %p������16������� 
	printf("%p\n",a+1); // a+i������a�����������ĵ�i��� �� ַ �� 
	printf("%p\n",a+2);
	printf("%p\n",a+3);
	
	Change_Array(a);
	Show_Array(a,5); // a����int *���� 
	
}
