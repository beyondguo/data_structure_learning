// �ṹ��
// �ṹ�� �Ƕ���һ���������ͣ����Ա��渴�ӵ�����
// �ṹ�����������е�����������������˷��� 

# include <stdio.h>
# include <string.h>

struct Student // struct Student����Ϊһ���������ͣ����ǵ�����Student����������������֮�󣬱����ǲ������ڴ�� 
{
	int id;
	char name[20];
	int age;
}; // ����ķֺŲ���ʡ�� 

int main(void)
{
	struct Student s1 = {1000, "gby", 21};
	printf("%d %s %d\n",s1.id, s1.name, s1.age);
	
	struct Student s2;
	s2.id = 1001;
	//s2.name = "xiao_ming";
	//[Error] incompatible types in assignment of 'const char [10]' to 'char [20]'
	strcpy(s2.name,"xiao_ming");
	s2.age = 12;
	printf("%d %s %d\n",s2.id, s2.name, s2.age);
	
	// �ṹ��ͨ��ָ�븳ֵ�ķ�ʽ��
	struct Student * ps;
	ps = &s1;
	ps->id = 1111; // ps->id �ȼ��� (*ps).id, ��(*ps).id �ȼ��� s1.id
	// ps��ָ��Ľṹ������е�id���ԡ� 
	printf("���޸ĺ��s1��idΪ��%d",s1.id);
	
	return 0;
}
