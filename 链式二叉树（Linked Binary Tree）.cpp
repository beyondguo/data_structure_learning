// 链式二叉树
/* 
这里我们就静态地创建一颗指定的树：
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
void PreTraverse(pBTN pT); //先序遍历 
void InTraverse(pBTN pT);  //中序遍历 
void PostTraverse(pBTN pT); //后序遍历 

int main(void){
	pBTN pT = CreateBTree();  // 创建二叉树，返回根节点的地址 
	printf("先序遍历：\n");
	PreTraverse(pT);
	printf("中序遍历：\n");
	InTraverse(pT);
	printf("后序遍历：\n");
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
	先访问根节点；
	再先序访问左子树；
	再先序访问右子树； 
	*/
	if (pT != NULL){
		printf("%c ",pT->data);
		PreTraverse(pT->pL);
		PreTraverse(pT->pR);
	}
	// 对，就是这么简单。
	// 其实说白了，每一个节点都是某棵树的根节点。
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
