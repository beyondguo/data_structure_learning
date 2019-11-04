// 如何写一个函数，来创建struct的一个实例

# include <stdio.h>
# include <malloc.h>

struct Stu
{
	int id;
	int age;
};

struct Stu * CreateStu(int id,int age);
void ShowStu(struct Stu s);

int main(void)
{
	struct Stu * ps;
	ps = CreateStu(1000,28);
	ShowStu(*ps);
	return 0;
} 
 
struct Stu * CreateStu(int id,int age)
{
	struct Stu * ps = (struct Stu *)malloc(sizeof(struct Stu));
	ps->id = id;
	ps->age = age;
	return ps;
}

void ShowStu(struct Stu s)
{
	printf("%d %d",s.id, s.age);
}
