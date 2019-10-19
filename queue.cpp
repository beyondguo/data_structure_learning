// ѭ������

# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

typedef struct Queue{  // ѭ�������ǻ���arrayд�ģ����Ը�array�Ľṹ�Ƚ����� 
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
	printf("�����������󳤶ȣ�maxlen=");
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
	printf("�������У�\n");
	if (!isEmpty(pQ)){
		// ������ѭ�����У�����f��r˭��˭С�ǲ�ȷ���ģ�����������ķ������϶�������⣺
		/* 
		for(int i=pQ->front;i<pQ->rear;i++)
			printf("%d ",pQ->pBase[i]);
		*/
		// ����Ӧʹ��f��r
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
		printf("�����������޷���ӣ�\n");
	else{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1)%pQ->maxlen;
		printf("�ɹ�����Ԫ�� %d\n",val); 

	}
}

int outQueue(PQUEUE pQ){
	if (isEmpty(pQ)){
		printf("�����ѿգ�����ɳ���\n");
		return NULL;
	}
		
	else{
		int val = pQ->pBase[pQ->front];
		pQ->front = (pQ->front+1)%pQ->maxlen;
		printf("���ӵ�Ԫ��Ϊ: %d\n",val);
		return val;
	}
}
