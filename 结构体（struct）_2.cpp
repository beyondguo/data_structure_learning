// �ֱ�д�������������ṹ�帳ֵ������� 
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
	struct Stu s; // ������ʵ��֮�󣬾ͷ������ڴ� 
	input_value(&s);
	best_output(&s);
	return 0;
}
 
void input_value(struct Stu * ps)
{
	ps->id = 1000;
	strcpy(ps->name,"gby");
// ��������д�� 
//	(*ps).id = 1000;
//	strcpy((*ps).name,"gby");
} 

// ���ַ��������ڴ�ࣨ��s��ֵ���βε�ʱ����Ҫ�´���һ����������ʱ�䳤 
void output_value(struct Stu s) 
{
	printf("%d %s",s.id, s.name);
}

void best_output(struct Stu * ps)
{
	printf("%d %s",ps->id,ps->name);
}
