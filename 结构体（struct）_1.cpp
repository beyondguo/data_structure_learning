// 结构体
// 结构体 是定义一种数据类型，可以保存复杂的数据
// 结构体跟面向对象中的类比起来，就是少了方法 

# include <stdio.h>
# include <string.h>

struct Student // struct Student整体为一个数据类型，不是单独的Student。而且这样定义了之后，本身是不开辟内存的 
{
	int id;
	char name[20];
	int age;
}; // 这里的分号不能省。 

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
	
	// 结构体通过指针赋值的方式：
	struct Student * ps;
	ps = &s1;
	ps->id = 1111; // ps->id 等价于 (*ps).id, 而(*ps).id 等价于 s1.id
	// ps所指向的结构体变量中的id属性。 
	printf("被修改后的s1的id为：%d",s1.id);
	
	return 0;
}
