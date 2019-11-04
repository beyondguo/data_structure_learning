//

# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

struct Array
{
	int * ph;
	int len; // the max length of the array
	int cnt; // current valid num of elements
};

// we wish to implement the following functions:
void init_arr(struct Array * p_arr, int len);
void append_arr(struct Array * p_arr, int value);
bool insert_arr(struct Array * p_arr, int index, int value);
bool delete_arr(struct Array * p_arr, int index);
int get(struct Array * p_arr, int index);
bool is_empty(struct Array * p_arr);
bool is_full(struct Array * p_arr);
void sort_arr(struct Array *p_arr, char type);
void inverse_arr(struct Array * p_arr);
void inverse_arr_2(struct Array * p_arr); 
void show_arr(struct Array * p_arr);


int main(void)
{
	struct Array arr;
	int len = 5;
	init_arr(&arr,len);
	show_arr(&arr);
	
	append_arr(&arr,3);
	append_arr(&arr,2);
	append_arr(&arr,4);
	show_arr(&arr);
	
	insert_arr(&arr,1,9);
	show_arr(&arr);
	insert_arr(&arr,3,100);
	insert_arr(&arr,3,100);	
	show_arr(&arr);
	
	delete_arr(&arr,3);
	show_arr(&arr);
	
	printf("index=%d处的值为%d.",1,get(&arr,1));
	
	printf("来一个翻转试试：\n原本的：\n"); 
	show_arr(&arr);
	inverse_arr(&arr);
	printf("翻转之后的：\n");
	show_arr(&arr);
	printf("翻转回来：\n");
	inverse_arr_2(&arr);
	show_arr(&arr);
	
	printf("按升序排列：\n");
	sort_arr(&arr,'b'); //这里还不能用双引号！而且还只能一个字母！查一查C中string的用法 
	show_arr(&arr);
	return 0;
}

void init_arr(struct Array * p_arr, int len) // 给arr开辟一个空间，并设置内部的属性 
{
	p_arr->ph = (int *)malloc(sizeof(int)*len); // 数组的空间是分配给ph的，ph是你想创建的数组的头指针 
	p_arr->len = len;
	p_arr->cnt = 0;
	printf("数组初始化成功！最大长度：%d，当前有效元素个数：%d\n",p_arr->len,p_arr->cnt);
}

bool is_empty(struct Array * p_arr)
{
	if (p_arr->cnt == 0)
		return true;
	else
		return false;
}

bool is_full(struct Array * p_arr)
{
	if (p_arr->cnt == p_arr->len)
		return true;
	else
		return false;
}

void append_arr(struct Array * p_arr, int value)
{
	if (is_full(p_arr)){
		printf("数组已满！不能追加！\n");
		exit(-1);
	}
	else{
		p_arr->ph[p_arr->cnt] = value;
		p_arr->cnt++;
		printf("恭喜你成功地在位置 %d 处添加了 %d !\n",p_arr->cnt,value);
	}
}

int get(struct Array * p_arr, int index)
{
	if (is_empty(p_arr)){
		printf("空的！\n");
		exit(-1);
	}
	else if (index<0 || index>p_arr->cnt-1){
		printf("你自己寻思寻思哪里有问题。。。\n");
		exit(-1);
	}
	else{
		return p_arr->ph[index];
	}
}

bool insert_arr(struct Array * p_arr, int index, int value)
{
	if (is_full(p_arr)){
		printf("数组已满！不能插入！\n");
		return false;
	}
	else if (index>=p_arr->cnt || index<0){
		printf("你插的位置不太对啊~~你可以插入的范围为：0~%d",p_arr->cnt-1);
		return false;
	}
	else{
		// 由于开辟的是连续的存储空间，所以这里只能把index之后的元素都往后移
		for (int i=p_arr->cnt-1; i>index-1; i--)
			p_arr->ph[i+1] = p_arr->ph[i];
		p_arr->ph[index] = value;
		p_arr->cnt++;
		printf("恭喜你成功地在位置 %d 处插入了 %d !\n",index,value);
		return true;
	}
}

bool delete_arr(struct Array * p_arr, int index)
{
	if (is_empty(p_arr)){
		printf("数组为空，你删个屁啊！\n");
		return false;
	}
	else if (index<0 || index>p_arr->cnt-1){
		printf("输入的index有误！有效范围为：0~%d\n",p_arr->cnt-1);
		return false;
	}
	else if (index==p_arr->cnt-1){
		p_arr->cnt--;
		printf("恭喜啊，成功把index=%d处的值给删除了，牛逼！\n",index);
		return true;
	}
	else{ // 要删除index处的值，只需要把index到cnt-2的每个位置都接收后面一个位置的值。 
		for (int i=index; i<=p_arr->cnt-2; i++){
			p_arr->ph[i] = p_arr->ph[i+1];
		}
		p_arr->cnt--;
		printf("恭喜啊，成功把index=%d处的值给删除了，牛逼！\n",index);
		return true;
	}
}

void inverse_arr(struct Array * p_arr)
{
	if (is_empty(p_arr)) printf("\n");
	else{
		for(int i=0;i<p_arr->cnt/2;i++){
			int temp;
			temp = p_arr->ph[i];
			p_arr->ph[i] = p_arr->ph[p_arr->cnt-1-i]; //这种关系画一画就知道了 i跟cnt-1-i对换就行了，无论奇偶 
			p_arr->ph[p_arr->cnt-1-i] = temp;
		}
	}
} //还有另一种思路，本质上是一样：

void inverse_arr_2(struct Array * p_arr)
{
	int temp;
	int i = 0; // 首 
	int j = p_arr->cnt-1; // 尾
	while(i<j){
		temp = p_arr->ph[i];
		p_arr->ph[i] = p_arr->ph[j];
		p_arr->ph[j] = temp;
		i++;
		j--;
	}
}

void sort_arr(struct Array *p_arr, char type)
{
	if (type == 'b'){
		for(int j=p_arr->cnt-1;j>0;j--){
			for(int i=0;i<j;i++){
				if (p_arr->ph[i]>p_arr->ph[i+1]){
					int t = p_arr->ph[i];
					p_arr->ph[i] = p_arr->ph[i+1];
					p_arr->ph[i+1] = t;
				}
			}
		}
	}
	else{
		printf("你这个type我不认识~\n");
	}
}

void show_arr(struct Array * p_arr)
{
	if (is_empty(p_arr))
		printf("数组为空！\n");
	else{
		for (int i=0; i<p_arr->cnt; i++)
			printf("%d ",p_arr->ph[i]); 
	// 这里尤其需要注意，我们的p_arr所指向的对象，不是数组，而是一个结构体，结构体内部的ph才是类似数组的东西 ！
	// 所以这里不能写成p_arr[i]。 
	}
	printf("\n");
		
		
}
