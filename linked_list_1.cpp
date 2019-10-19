// Linked List 链表
/* 
-链表的插入元素 
	比方在p指向的节点后面插入一个q,那么可以用两行代码搞定： 
	q->p_next = p->p_next;
	p->p_next = q;
	
-链表删除元素
	比方删除p节点后面的节点，能否这样写呢：
	p->p_next = p->p_next->p_next;
	【不行】！！ 
	为什么？
	直觉上似乎就是这么简单，但是由于C++没有自动清理内存的功能，所以这样写会导致中间那个节点的内存泄露，
	所谓内存泄露，就是指我们的内存越用越少，因为很多内存你不用了却没有释放。
	所以，【正确的做法】应该是：
	r = p->p_next;
	p->p_next = p->p_next->p_next;
	free(r);  // 或 delete r; 
*/ 

# include <stdio.h>
# include <malloc.h>

typedef struct Node{
	int data; //数据域
	struct Node * pNext; //指针域 
}NODE, *PNODE; // NODE等价于struct Node，*PNODE等价于 * struct Node； 

// 功能函数声明： 
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int get_length(PNODE pHead);
bool insert_list(PNODE pHead, int idx, int val);
bool delete_list(PNODE pHead, int idx);
void sort_list(PNODE pHead);


int main(void){
	PNODE pHead = create_list(); // 希望有一个函数，可以创建一个非循环单链表 
	traverse_list(pHead); // 希望有一个函数，可以遍历这个链表
	
	if (! is_empty(pHead)) printf("不为空~\n"); else printf("为空！\n");
	
	printf("插入某个元素：\n"); 
	insert_list(pHead,2,100);
	traverse_list(pHead);
	
	printf("链表长度为：%d\n",get_length(pHead)); 
	
	printf("给链表排序：\n"); 
	sort_list(pHead);
	traverse_list(pHead);
	
	printf("删除某个元素：\n"); 
	delete_list(pHead,3);
	traverse_list(pHead);
	
	
	return 0;
}


PNODE create_list(void){
	// 思路：首先得定义一个头指针，这是链表的根基
	// 然后用户输入长度，然后依次添加每一个节点
	// 难点在于如何一个个地添加节点
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE)); 
	// 这里有一些注意事项和疑问：
	// 1.为什么要使用malloc？为何不能直接PNODE pHead;就完事儿了？开辟空间是干嘛？难道定义一个变量不是直接开辟空间吗？
	// 2.后面的sizeof，不能写PNODE，而应该是NODE的size，为啥？因为malloc就是开辟空间后返回一个指针，默认是void*类型，所以我们要转换一下
	int len;
	printf("请定义链表的长度： len=");
	scanf("%d",&len); 
	
	// 定义一个尾结点，作为影子节点，始终附在最后一个节点上，起到传递作用
	PNODE pTail = pHead;
	pTail->pNext = NULL; 
	
	for(int i=0; i<len; i++){
		int val;
		printf("输入第%d个节点的值：",i+1);
		scanf("%d",&val);
		
		// 定义一个新节点，赋值。同时，它也是目前的最后一个节点，所以把指针域设为NULL： 
		PNODE p = (PNODE)malloc(sizeof(NODE));
		p->data = val;
		p->pNext = NULL;
		
		// pTail是附在上一个尾结点上，所以使用pTail把上一个节点和当前节点连接起来，完毕之后，就附在新的尾结点上： 
		pTail->pNext = p;
		pTail = p;
	}
	return pHead;
} 

void traverse_list(PNODE pHead){
	// 如何遍历？思路：
	// 我们知道头指针，那么依次顺着指针往下读，直到节点的指针域为NULL就终止。所以需要一个指针p来不断跳动
	PNODE p = pHead->pNext;
	while(NULL != p){
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool is_empty(PNODE pHead){
	if (pHead->pNext==NULL) 
		return true;
	else 
		return false;
}

int get_length(PNODE pHead){
	int len = 0;
	PNODE p = pHead->pNext;
	while(NULL != p){
		len++;
		p = p->pNext;
	}
	return len;
}

void sort_list(PNODE pHead){
	// 从本质上讲，链表和数组都属于线性结构，那么他们的排序算法从逻辑上看应该是一样的
	// 我们可以先写出数组是怎么排序的，以冒泡排序为例：
	int len = get_length(pHead);

	/*
	int i,j,t;
	for(i=0;i<len-1;i++){
		for(j=i+1;j<len;j++){
			if (a[i]>a[j]){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	*/
	// 链表实际上逻辑是一样，无非就是元素不能通过下标来查询
	// 但是，链表可以通过->next操作，转移到下一个，所以可以通过这个来改写j=i+1,i++这些操作
	PNODE p,q;
	int i,j,t;
	for(i=0,p=pHead->pNext; i<len-1; i++,p=p->pNext){
		for(j=i+1,q=p->pNext; j<len; j++,q=q->pNext){
			if (p->data > q->data){
				t = q->data;
				q->data = p->data;
				p->data = t;
			}
		}
	}
	
}


bool insert_list(PNODE pHead, int idx, int val){
	
	// 插入的思路很简单，把那个位置前面的node的指针指过来，把该node的指针指到那个位置
	if(idx<0 || idx>get_length(pHead)) return false; 

	PNODE p = pHead;
	PNODE q = (PNODE)malloc(sizeof(NODE)); // 这里是使用malloc开辟了空间，如果直接PNODE q;则后面在 q->data = val的时候会崩溃。WHY？？？ 
	//这样写就可以，写成 PNODE q = pHead就会导致idx前面的丢失，因为你后面由 q->pNext = p->pNext，等价于qHead->pNext = p->pNext； 
	// 写成PNODE p,q = pHead会导致程序崩溃。。。WHY？？？ 
	q->data = val;

	
	// 让p挪到要插入的前一个node那里： 
	for(int i=0;i<idx;i++){
		p = p->pNext;
	}
	// 接下来就简单了： 
	q->pNext = p->pNext;
	p->pNext = q;
	return true;
}


bool delete_list(PNODE pHead, int idx){
	// 删除的流程跟insert一模一样，都要先找到位置，然后对指针域进行一顿操作
	// 值得注意的就是内存释放的问题
	
	if (idx<0 || idx>=get_length(pHead)) return false;
	
	PNODE p = pHead;
	for (int i=0;i<idx;i++){
		p = p->pNext;
	}
	PNODE r = p->pNext;
	p->pNext = p->pNext->pNext;
	free(r);
	return true;
}
