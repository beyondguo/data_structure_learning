// ��ʽ������
/* 
�������Ǿ;�̬�ش���һ��ָ��������
     A
    / \
   B   C
      /
	 D
      \
	   E
*/ 
# include <stdio.h>
# include <malloc.h>

typedef struct BTNode{            // binary tree node
	int data;
	struct BTNode * pL;   // pointer of Left Child
	struct BTNode * pR;   // pointer of Right Child
}BTN,* pBTN;

pBTN CreateBTree(void); 
void PreTraverse(pBTN pT); //������� 
void InTraverse(pBTN pT);  //������� 
void PostTraverse(pBTN pT); //������� 

int main(void){
	pBTN pT = CreateBTree();  // ���������������ظ��ڵ�ĵ�ַ 
	printf("���������\n");
	PreTraverse(pT);
	printf("���������\n");
	InTraverse(pT);
	printf("���������\n");
	PostTraverse(pT);
	return 0;
}

pBTN CreateBTree(void){
	pBTN pA = (pBTN)malloc(sizeof(BTN));
	pBTN pB = (pBTN)malloc(sizeof(BTN));
	pBTN pC = (pBTN)malloc(sizeof(BTN));
	pBTN pD = (pBTN)malloc(sizeof(BTN));
	pBTN pE = (pBTN)malloc(sizeof(BTN));
	
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	
	pA->pL = pB;
	pA->pR = pC;
	pB->pL = pB->pR = NULL;
	pC->pL = pD;
	pC->pR = NULL;
	pD->pL = NULL;
	pD->pR = pE; 
	pE->pL = pE->pR = NULL;
	
	return pA;
}

void PreTraverse(pBTN pT){
	/*
	�ȷ��ʸ��ڵ㣻
	�����������������
	����������������� 
	*/
	if (pT != NULL){
		printf("%c ",pT->data);
		PreTraverse(pT->pL);
		PreTraverse(pT->pR);
	}
	// �ԣ�������ô�򵥡�
	// ��ʵ˵���ˣ�ÿһ���ڵ㶼��ĳ�����ĸ��ڵ㡣
}

void InTraverse(pBTN pT){
	if (pT != NULL){
		InTraverse(pT->pL);
		printf("%c ",pT->data);
		InTraverse(pT->pR);
	}
}

void PostTraverse(pBTN pT){
	if (pT != NULL){
		PostTraverse(pT->pL);
		PostTraverse(pT->pR);
		printf("%c ",pT->data);
	}
}
