// 递归之——汉诺塔问题

# include <stdio.h>


int num_move_hnt(int n);  // 统计移动次数 
int move_hnt(int n, char A, char B, char C); // 更高级一点，不管统计次数，还输出移动规则 

int main(void){
	int n;
	while(true){
	printf("请输入盘子个数，n=");
	scanf("%d",&n);
//	printf("挪%d个盘子到另一个柱子上需要移动%d次\n",n,num_move_hnt(n));
	printf("把A柱子上的%d个盘子移动到C柱子上的方法是：\n",n);
	int steps = move_hnt(n,'A','B','C');
	printf("共需要移动%d次~\n\n",steps); 
    }
    return 0; 
} 


int num_move_hnt(int n){
	if (n==0) return 0;
	else if (n==1) return 1;
	else if (n==2) return 3;
	else{
		return 2*num_move_hnt(n-1)+1;
	}
}

int move_hnt(int n, char A, char B, char C){
	// A柱子代表函数起始状态下 所有盘子的位置，C代表当前函数的目标柱子，B则是辅助柱子
	//注意，随着程序的不断递归，每次的起始和目标柱子可能都不一样
	if (n==0) {
		printf("不用移动了。\n");
		return 0;
	}
	if (n==1){
		printf("将当前这个编号为%d的盘子从%c柱子移动到%c柱子上\n",n,A,C);
		return 1;
	}
	if (n>1){
		// 第一步，将上面的n-1个盘子从A移动到B 
		int step1 = move_hnt(n-1,A,C,B);
		// 第二步，将第n个盘子从A移动到C
		printf("将当前这个编号为%d的盘子从%c柱子移动到%c柱子上\n",n,A,C);
		// 第三步，将B上面的n-1个盘子再移动到C
		int step2 = move_hnt(n-1,B,A,C); 
		return step1+step2+1;
	}
	 
}


