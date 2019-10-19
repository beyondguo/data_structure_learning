// ����չʾ���ǡ���̬ջ�� 
// ջ��һ������ָ��pTop��һ���ײ�ָ��pBottom
# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>


typedef struct Node{
	int data; //������
	struct Node * pNext; //ָ���� 
}NODE, *PNODE; 

typedef struct Stack{
	PNODE pTop;
	PNODE pBottom; // ָ�����ջ�ײ����Ǹ�û��ʵ�ʺ���Ľڵ� �����������������д�ĳ���������ȫû�õ����ѽ�� 
}STACK, *PSTACK;


void initSTACK(PSTACK pS);
bool pushSTACK(PSTACK pS, int val);
int popSTACK(PSTACK pS);
void traverse(PSTACK pS);
void clear(PSTACK pS); 

int main(void){
	STACK S; 
	initSTACK(&S);
	for(int i=0;i<5;i++) pushSTACK(&S,i);
	traverse(&S);
	for(int i=0;i<3;i++) popSTACK(&S);
	traverse(&S);
	clear(&S);
	traverse(&S);
	
	return 0;
} 

void initSTACK(PSTACK pS){  // ��ʼ����Ŀ�ģ������γ�һ����ջ���Ǿ��Ƕ����ײ�ָ�붼ָ��һ���սڵ� 
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	pS->pBottom = pS->pTop;
	pS->pTop->pNext = NULL; 
}

bool pushSTACK(PSTACK pS, int val){ // ѹջ���κ�ʱ���ǿ��Եģ�û������ 
	PNODE p = (PNODE)malloc(sizeof(NODE));
	p->data = val;
	p->pNext = pS->pTop;
	pS->pTop = p;
}

int popSTACK(PSTACK pS){ // ��ջ������û�����ƣ�ֻҪ������ 
	if (pS->pTop->pNext == NULL) return NULL;
	PNODE p = pS->pTop;
	pS->pTop = pS->pTop->pNext;
	return p->data;
	free(p);
}

void traverse(PSTACK pS){
	printf("��ӡջ�����ݣ�\n");
	PNODE p = pS->pTop;
	while(p->pNext != NULL){
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
} 

void clear(PSTACK pS){
	PNODE p = pS->pTop;
	PNODE q = p->pNext;
	while(q != NULL){
		free(p);
		p = q;
		q = p->pNext;
	}
	pS->pTop = p;
}

