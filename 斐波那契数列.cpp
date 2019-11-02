// 斐波那契数列

# include <stdio.h>
 
int Fibonacci(int n); //返回Fibonacci数列第n项的值

int main(void){
	
	int n;
	printf("输入n=");
	scanf("%d",&n);
	printf("Fibonacci数列第%d项的值为：%d\n",n,Fibonacci(n));
	return 0;
}

int Fibonacci(int n){
	if (n==1) return 1;
	if (n==2) return 2;
	if (n>2){
		return Fibonacci(n-1)+Fibonacci(n-2);
	}
}
