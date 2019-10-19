// 这里展示的是“动态栈” 
// 栈有一个顶部指针pTop和一个底部指针pBottom
# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>


typedef struct Node{
	int data; //数据域
	struct Node * pNext; //指针域 
}NODE, *PNODE; 

typedef struct Stack{
	PNODE pTop;
	PNODE pBottom; // 指向的是栈底部的那个没有实际含义的节点 ？？？真的有用吗？我写的程序里面完全没用到这个呀！ 
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

void initSTACK(PSTACK pS){  // 初始化的目的，就是形成一个空栈，那就是顶部底部指针都指向一个空节点 
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	pS->pBottom = pS->pTop;
	pS->pTop->pNext = NULL; 
}

bool pushSTACK(PSTACK pS, int val){ // 压栈在任何时候都是可以的，没有限制 
	PNODE p = (PNODE)malloc(sizeof(NODE));
	p->data = val;
	p->pNext = pS->pTop;
	pS->pTop = p;
}

int popSTACK(PSTACK pS){ // 出栈，基本没有限制，只要有数据 
	if (pS->pTop->pNext == NULL) return NULL;
	PNODE p = pS->pTop;
	pS->pTop = pS->pTop->pNext;
	return p->data;
	free(p);
}

void traverse(PSTACK pS){
	printf("打印栈的数据：\n");
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

