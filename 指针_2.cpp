// ͨ��ָ�������ʹ�ú����ı������ֵ 

#include <stdio.h>

void f1(int i)
{
	i = 100;
} 

void f2(int *i) // ���Ƕ�����һ�����ֽ�*i���βΣ����Ƕ�����һ���βΣ����β����ֽ���i��������int *�� 
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
