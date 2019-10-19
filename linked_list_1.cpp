// Linked List ����
/* 
-����Ĳ���Ԫ�� 
	�ȷ���pָ��Ľڵ�������һ��q,��ô���������д���㶨�� 
	q->p_next = p->p_next;
	p->p_next = q;
	
-����ɾ��Ԫ��
	�ȷ�ɾ��p�ڵ����Ľڵ㣬�ܷ�����д�أ�
	p->p_next = p->p_next->p_next;
	�����С����� 
	Ϊʲô��
	ֱ�����ƺ�������ô�򵥣���������C++û���Զ������ڴ�Ĺ��ܣ���������д�ᵼ���м��Ǹ��ڵ���ڴ�й¶��
	��ν�ڴ�й¶������ָ���ǵ��ڴ�Խ��Խ�٣���Ϊ�ܶ��ڴ��㲻����ȴû���ͷš�
	���ԣ�����ȷ��������Ӧ���ǣ�
	r = p->p_next;
	p->p_next = p->p_next->p_next;
	free(r);  // �� delete r; 
*/ 

# include <stdio.h>
# include <malloc.h>

typedef struct Node{
	int data; //������
	struct Node * pNext; //ָ���� 
}NODE, *PNODE; // NODE�ȼ���struct Node��*PNODE�ȼ��� * struct Node�� 

// ���ܺ��������� 
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int get_length(PNODE pHead);
bool insert_list(PNODE pHead, int idx, int val);
bool delete_list(PNODE pHead, int idx);
void sort_list(PNODE pHead);


int main(void){
	PNODE pHead = create_list(); // ϣ����һ�����������Դ���һ����ѭ�������� 
	traverse_list(pHead); // ϣ����һ�����������Ա����������
	
	if (! is_empty(pHead)) printf("��Ϊ��~\n"); else printf("Ϊ�գ�\n");
	
	printf("����ĳ��Ԫ�أ�\n"); 
	insert_list(pHead,2,100);
	traverse_list(pHead);
	
	printf("������Ϊ��%d\n",get_length(pHead)); 
	
	printf("����������\n"); 
	sort_list(pHead);
	traverse_list(pHead);
	
	printf("ɾ��ĳ��Ԫ�أ�\n"); 
	delete_list(pHead,3);
	traverse_list(pHead);
	
	
	return 0;
}


PNODE create_list(void){
	// ˼·�����ȵö���һ��ͷָ�룬��������ĸ���
	// Ȼ���û����볤�ȣ�Ȼ���������ÿһ���ڵ�
	// �ѵ��������һ��������ӽڵ�
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE)); 
	// ������һЩע����������ʣ�
	// 1.ΪʲôҪʹ��malloc��Ϊ�β���ֱ��PNODE pHead;�����¶��ˣ����ٿռ��Ǹ���ѵ�����һ����������ֱ�ӿ��ٿռ���
	// 2.�����sizeof������дPNODE����Ӧ����NODE��size��Ϊɶ����Ϊmalloc���ǿ��ٿռ�󷵻�һ��ָ�룬Ĭ����void*���ͣ���������Ҫת��һ��
	int len;
	printf("�붨������ĳ��ȣ� len=");
	scanf("%d",&len); 
	
	// ����һ��β��㣬��ΪӰ�ӽڵ㣬ʼ�ո������һ���ڵ��ϣ��𵽴�������
	PNODE pTail = pHead;
	pTail->pNext = NULL; 
	
	for(int i=0; i<len; i++){
		int val;
		printf("�����%d���ڵ��ֵ��",i+1);
		scanf("%d",&val);
		
		// ����һ���½ڵ㣬��ֵ��ͬʱ����Ҳ��Ŀǰ�����һ���ڵ㣬���԰�ָ������ΪNULL�� 
		PNODE p = (PNODE)malloc(sizeof(NODE));
		p->data = val;
		p->pNext = NULL;
		
		// pTail�Ǹ�����һ��β����ϣ�����ʹ��pTail����һ���ڵ�͵�ǰ�ڵ��������������֮�󣬾͸����µ�β����ϣ� 
		pTail->pNext = p;
		pTail = p;
	}
	return pHead;
} 

void traverse_list(PNODE pHead){
	// ��α�����˼·��
	// ����֪��ͷָ�룬��ô����˳��ָ�����¶���ֱ���ڵ��ָ����ΪNULL����ֹ��������Ҫһ��ָ��p����������
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
	// �ӱ����Ͻ�����������鶼�������Խṹ����ô���ǵ������㷨���߼��Ͽ�Ӧ����һ����
	// ���ǿ�����д����������ô����ģ���ð������Ϊ����
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
	// ����ʵ�����߼���һ�����޷Ǿ���Ԫ�ز���ͨ���±�����ѯ
	// ���ǣ��������ͨ��->next������ת�Ƶ���һ�������Կ���ͨ���������дj=i+1,i++��Щ����
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
	
	// �����˼·�ܼ򵥣����Ǹ�λ��ǰ���node��ָ��ָ�������Ѹ�node��ָ��ָ���Ǹ�λ��
	if(idx<0 || idx>get_length(pHead)) return false; 

	PNODE p = pHead;
	PNODE q = (PNODE)malloc(sizeof(NODE)); // ������ʹ��malloc�����˿ռ䣬���ֱ��PNODE q;������� q->data = val��ʱ��������WHY������ 
	//����д�Ϳ��ԣ�д�� PNODE q = pHead�ͻᵼ��idxǰ��Ķ�ʧ����Ϊ������� q->pNext = p->pNext���ȼ���qHead->pNext = p->pNext�� 
	// д��PNODE p,q = pHead�ᵼ�³������������WHY������ 
	q->data = val;

	
	// ��pŲ��Ҫ�����ǰһ��node��� 
	for(int i=0;i<idx;i++){
		p = p->pNext;
	}
	// �������ͼ��ˣ� 
	q->pNext = p->pNext;
	p->pNext = q;
	return true;
}


bool delete_list(PNODE pHead, int idx){
	// ɾ�������̸�insertһģһ������Ҫ���ҵ�λ�ã�Ȼ���ָ�������һ�ٲ���
	// ֵ��ע��ľ����ڴ��ͷŵ�����
	
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
