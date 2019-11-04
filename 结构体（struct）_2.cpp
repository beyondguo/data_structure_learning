// 分别写两个函数，给结构体赋值和输出： 
# include <stdio.h>
# include <string.h>

struct Stu
{
	int id;
	char name[20];
};

void input_value(struct Stu *s);
void output_value(struct Stu s);
void best_output(struct Stu * ps);
int main(void)
{
	struct Stu s; // 创建了实例之后，就分配了内存 
	input_value(&s);
	best_output(&s);
	return 0;
}
 
void input_value(struct Stu * ps)
{
	ps->id = 1000;
	strcpy(ps->name,"gby");
// 或者这样写： 
//	(*ps).id = 1000;
//	strcpy((*ps).name,"gby");
} 

// 这种方法消耗内存多（在s赋值给形参的时候，需要新创建一个变量），时间长 
void output_value(struct Stu s) 
{
	printf("%d %s",s.id, s.name);
}

void best_output(struct Stu * ps)
{
	printf("%d %s",ps->id,ps->name);
}
