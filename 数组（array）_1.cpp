//

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

struct Array
{
	int * ph;
	int len; // the max length of the array
	int cnt; // current valid num of elements
};

// we wish to implement the following functions:
void init_arr(struct Array * p_arr, int len);
void append_arr(struct Array * p_arr, int value);
bool insert_arr(struct Array * p_arr, int index, int value);
bool delete_arr(struct Array * p_arr, int index);
int get(struct Array * p_arr, int index);
bool is_empty(struct Array * p_arr);
bool is_full(struct Array * p_arr);
void sort_arr(struct Array *p_arr, char type);
void inverse_arr(struct Array * p_arr);
void inverse_arr_2(struct Array * p_arr); 
void show_arr(struct Array * p_arr);


int main(void)
{
	struct Array arr;
	int len = 5;
	init_arr(&arr,len);
	show_arr(&arr);
	
	append_arr(&arr,3);
	append_arr(&arr,2);
	append_arr(&arr,4);
	show_arr(&arr);
	
	insert_arr(&arr,1,9);
	show_arr(&arr);
	insert_arr(&arr,3,100);
	insert_arr(&arr,3,100);	
	show_arr(&arr);
	
	delete_arr(&arr,3);
	show_arr(&arr);
	
	printf("index=%d����ֵΪ%d.",1,get(&arr,1));
	
	printf("��һ����ת���ԣ�\nԭ���ģ�\n"); 
	show_arr(&arr);
	inverse_arr(&arr);
	printf("��ת֮��ģ�\n");
	show_arr(&arr);
	printf("��ת������\n");
	inverse_arr_2(&arr);
	show_arr(&arr);
	
	printf("���������У�\n");
	sort_arr(&arr,'b'); //���ﻹ������˫���ţ����һ�ֻ��һ����ĸ����һ��C��string���÷� 
	show_arr(&arr);
	return 0;
}

void init_arr(struct Array * p_arr, int len) // ��arr����һ���ռ䣬�������ڲ������� 
{
	p_arr->ph = (int *)malloc(sizeof(int)*len); // ����Ŀռ��Ƿ����ph�ģ�ph�����봴���������ͷָ�� 
	p_arr->len = len;
	p_arr->cnt = 0;
	printf("�����ʼ���ɹ�����󳤶ȣ�%d����ǰ��ЧԪ�ظ�����%d\n",p_arr->len,p_arr->cnt);
}

bool is_empty(struct Array * p_arr)
{
	if (p_arr->cnt == 0)
		return true;
	else
		return false;
}

bool is_full(struct Array * p_arr)
{
	if (p_arr->cnt == p_arr->len)
		return true;
	else
		return false;
}

void append_arr(struct Array * p_arr, int value)
{
	if (is_full(p_arr)){
		printf("��������������׷�ӣ�\n");
		exit(-1);
	}
	else{
		p_arr->ph[p_arr->cnt] = value;
		p_arr->cnt++;
		printf("��ϲ��ɹ�����λ�� %d ������� %d !\n",p_arr->cnt,value);
	}
}

int get(struct Array * p_arr, int index)
{
	if (is_empty(p_arr)){
		printf("�յģ�\n");
		exit(-1);
	}
	else if (index<0 || index>p_arr->cnt-1){
		printf("���Լ�Ѱ˼Ѱ˼���������⡣����\n");
		exit(-1);
	}
	else{
		return p_arr->ph[index];
	}
}

bool insert_arr(struct Array * p_arr, int index, int value)
{
	if (is_full(p_arr)){
		printf("�������������ܲ��룡\n");
		return false;
	}
	else if (index>=p_arr->cnt || index<0){
		printf("����λ�ò�̫�԰�~~����Բ���ķ�ΧΪ��0~%d",p_arr->cnt-1);
		return false;
	}
	else{
		// ���ڿ��ٵ��������Ĵ洢�ռ䣬��������ֻ�ܰ�index֮���Ԫ�ض�������
		for (int i=p_arr->cnt-1; i>index-1; i--)
			p_arr->ph[i+1] = p_arr->ph[i];
		p_arr->ph[index] = value;
		p_arr->cnt++;
		printf("��ϲ��ɹ�����λ�� %d �������� %d !\n",index,value);
		return true;
	}
}

bool delete_arr(struct Array * p_arr, int index)
{
	if (is_empty(p_arr)){
		printf("����Ϊ�գ���ɾ��ƨ����\n");
		return false;
	}
	else if (index<0 || index>p_arr->cnt-1){
		printf("�����index������Ч��ΧΪ��0~%d\n",p_arr->cnt-1);
		return false;
	}
	else if (index==p_arr->cnt-1){
		p_arr->cnt--;
		printf("��ϲ�����ɹ���index=%d����ֵ��ɾ���ˣ�ţ�ƣ�\n",index);
		return true;
	}
	else{ // Ҫɾ��index����ֵ��ֻ��Ҫ��index��cnt-2��ÿ��λ�ö����պ���һ��λ�õ�ֵ�� 
		for (int i=index; i<=p_arr->cnt-2; i++){
			p_arr->ph[i] = p_arr->ph[i+1];
		}
		p_arr->cnt--;
		printf("��ϲ�����ɹ���index=%d����ֵ��ɾ���ˣ�ţ�ƣ�\n",index);
		return true;
	}
}

void inverse_arr(struct Array * p_arr)
{
	if (is_empty(p_arr)) printf("\n");
	else{
		for(int i=0;i<p_arr->cnt/2;i++){
			int temp;
			temp = p_arr->ph[i];
			p_arr->ph[i] = p_arr->ph[p_arr->cnt-1-i]; //���ֹ�ϵ��һ����֪���� i��cnt-1-i�Ի������ˣ�������ż 
			p_arr->ph[p_arr->cnt-1-i] = temp;
		}
	}
} //������һ��˼·����������һ����

void inverse_arr_2(struct Array * p_arr)
{
	int temp;
	int i = 0; // �� 
	int j = p_arr->cnt-1; // β
	while(i<j){
		temp = p_arr->ph[i];
		p_arr->ph[i] = p_arr->ph[j];
		p_arr->ph[j] = temp;
		i++;
		j--;
	}
}

void sort_arr(struct Array *p_arr, char type)
{
	if (type == 'b'){
		for(int j=p_arr->cnt-1;j>0;j--){
			for(int i=0;i<j;i++){
				if (p_arr->ph[i]>p_arr->ph[i+1]){
					int t = p_arr->ph[i];
					p_arr->ph[i] = p_arr->ph[i+1];
					p_arr->ph[i+1] = t;
				}
			}
		}
	}
	else{
		printf("�����type�Ҳ���ʶ~\n");
	}
}

void show_arr(struct Array * p_arr)
{
	if (is_empty(p_arr))
		printf("����Ϊ�գ�\n");
	else{
		for (int i=0; i<p_arr->cnt; i++)
			printf("%d ",p_arr->ph[i]); 
	// ����������Ҫע�⣬���ǵ�p_arr��ָ��Ķ��󣬲������飬����һ���ṹ�壬�ṹ���ڲ���ph������������Ķ��� ��
	// �������ﲻ��д��p_arr[i]�� 
	}
	printf("\n");
		
		
}
