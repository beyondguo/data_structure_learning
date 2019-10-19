// 循环队列

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct Queue{  // 循环队列是基于array写的，所以跟array的结构比较类似 
	int * pBase;
	int front;
	int rear;
	int maxlen;
}QUEUE,*PQUEUE;

void init(PQUEUE pQ);
bool isFull(PQUEUE pQ);
bool isEmpty(PQUEUE pQ);
void inQueue(PQUEUE pQ, int val);
int outQueue(PQUEUE pQ);
void traverse(PQUEUE pQ);

int main(void){
	QUEUE Q;
	init(&Q);
	for(int i=0;i<5;i++) inQueue(&Q,i+1);
	traverse(&Q);
	for(int i=0;i<6;i++) outQueue(&Q);
	traverse(&Q);
	for(int i=0;i<3;i++) inQueue(&Q,i*3);
	traverse(&Q);
	return 0;
}

void init(PQUEUE pQ){
	int maxlen;
	printf("请输入队列最大长度：maxlen=");
	scanf("%d",&maxlen);
	pQ->pBase = (int *)malloc(sizeof(int)*maxlen);
	pQ->front = 0;
	pQ->rear = 0;
	pQ->maxlen = maxlen;
}

bool isFull(PQUEUE pQ){
	if (pQ->front == (pQ->rear+1)%pQ->maxlen)
		return true;
	else
		return false;
}

bool isEmpty(PQUEUE pQ){
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}

void traverse(PQUEUE pQ){
	printf("遍历队列：\n");
	if (!isEmpty(pQ)){
		// 由于是循环队列，所以f和r谁大谁小是不确定的，所以用下面的方法做肯定会出问题：
		/* 
		for(int i=pQ->front;i<pQ->rear;i++)
			printf("%d ",pQ->pBase[i]);
		*/
		// 所以应使用f和r
		int f = pQ->front;
		int r = pQ->rear;
		while(f!=r){
			printf("%d ",pQ->pBase[f]);
			f = (f+1)%pQ->maxlen;
		} 
		printf("\n");
	}
}

void inQueue(PQUEUE pQ, int val){
	if (isFull(pQ))
		printf("队列已满！无法入队！\n");
	else{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1)%pQ->maxlen;
		printf("成功加入元素 %d\n",val); 

	}
}

int outQueue(PQUEUE pQ){
	if (isEmpty(pQ)){
		printf("队列已空！无物可出！\n");
		return NULL;
	}
		
	else{
		int val = pQ->pBase[pQ->front];
		pQ->front = (pQ->front+1)%pQ->maxlen;
		printf("出队的元素为: %d\n",val);
		return val;
	}
}
