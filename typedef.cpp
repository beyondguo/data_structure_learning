// typedef的用法

# include <stdio.h>
# include <string.h>

typedef struct Student{
	int id;
	char name[20];
}ST; // typedef的作用就是给一个数据类型重新取一个名字，这样可以更加方便地使用 

/*
typedef struct Student{
	int id;
	char name[20];
}* PST;
如果是这样形式的话，那PST就等价于struct Student * 这个类型，是一个指针 
*/ 

/*
typedef struct Student{
	int id;
	char name[20];
}* PST ST;
如果是这样形式的话，那PST就等价于struct Student * 这个类型;
而ST还是代表struct Student这个东西。 
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
