// 쳲���������

# include <stdio.h>
 
int Fibonacci(int n); //����Fibonacci���е�n���ֵ

int main(void){
	
	int n;
	printf("����n=");
	scanf("%d",&n);
	printf("Fibonacci���е�%d���ֵΪ��%d\n",n,Fibonacci(n));
	return 0;
}

int Fibonacci(int n){
	if (n==1) return 1;
	if (n==2) return 2;
	if (n>2){
		return Fibonacci(n-1)+Fibonacci(n-2);
	}
}
