// typedef���÷�

# include <stdio.h>
# include <string.h>

typedef struct Student{
	int id;
	char name[20];
}ST; // typedef�����þ��Ǹ�һ��������������ȡһ�����֣��������Ը��ӷ����ʹ�� 

/*
typedef struct Student{
	int id;
	char name[20];
}* PST;
�����������ʽ�Ļ�����PST�͵ȼ���struct Student * ������ͣ���һ��ָ�� 
*/ 

/*
typedef struct Student{
	int id;
	char name[20];
}* PST ST;
�����������ʽ�Ļ�����PST�͵ȼ���struct Student * �������;
��ST���Ǵ���struct Student��������� 
*/ 

int main(){
	
	struct Student st1;
	st1.id = 1;
	strcpy(st1.name,"gby");
	
	ST st2;
	st2.id = 1;
	strcpy(st2.name,"zhangsan");
	
	printf("st1.id=%d, st1.name=%s\n",st1.id, st1.name);
	printf("st2.id=%d, st2.name=%s\n",st2.id, st2.name); 
		
	return 0;
}
