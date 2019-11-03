// 快速排序

# include <stdio.h> 


void QuickSort(int * a, int low, int high);
int FindPos(int * a, int low, int high);

int main(void){
	int a[6] = {-5,2,1,7,-9,3};
	int i;
	
	QuickSort(a,0,5); //后面两参数为a收尾的index
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	 
	return 0;
}

void QuickSort(int * a, int low, int high){
	if (low < high){
		// 找到第一个元素的位置 ： 
		int pos = FindPos(a, low, high); 
		// 再分别递归： 
		QuickSort(a,low,pos-1);
		QuickSort(a,pos+1,high);
	}
}

int FindPos(int * a, int low, int high){
	int val = a[low];
	while (low<high){
		while (a[high]>=val && low<high)  //注意这里low<high容易漏 
			high--;
		a[low] = a[high];
		
		while (a[low]<=val && low<high)
			low++;
		a[high] = a[low];
	}
	a[low] = val;
	
	return low;
}

