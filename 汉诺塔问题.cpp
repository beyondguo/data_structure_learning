// �ݹ�֮������ŵ������

# include <stdio.h>


int num_move_hnt(int n);  // ͳ���ƶ����� 
int move_hnt(int n, char A, char B, char C); // ���߼�һ�㣬����ͳ�ƴ�����������ƶ����� 

int main(void){
	int n;
	while(true){
	printf("���������Ӹ�����n=");
	scanf("%d",&n);
//	printf("Ų%d�����ӵ���һ����������Ҫ�ƶ�%d��\n",n,num_move_hnt(n));
	printf("��A�����ϵ�%d�������ƶ���C�����ϵķ����ǣ�\n",n);
	int steps = move_hnt(n,'A','B','C');
	printf("����Ҫ�ƶ�%d��~\n\n",steps); 
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
	// A���Ӵ�������ʼ״̬�� �������ӵ�λ�ã�C����ǰ������Ŀ�����ӣ�B���Ǹ�������
	//ע�⣬���ų���Ĳ��ϵݹ飬ÿ�ε���ʼ��Ŀ�����ӿ��ܶ���һ��
	if (n==0) {
		printf("�����ƶ��ˡ�\n");
		return 0;
	}
	if (n==1){
		printf("����ǰ������Ϊ%d�����Ӵ�%c�����ƶ���%c������\n",n,A,C);
		return 1;
	}
	if (n>1){
		// ��һ�����������n-1�����Ӵ�A�ƶ���B 
		int step1 = move_hnt(n-1,A,C,B);
		// �ڶ���������n�����Ӵ�A�ƶ���C
		printf("����ǰ������Ϊ%d�����Ӵ�%c�����ƶ���%c������\n",n,A,C);
		// ����������B�����n-1���������ƶ���C
		int step2 = move_hnt(n-1,B,A,C); 
		return step1+step2+1;
	}
	 
}


