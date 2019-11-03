// ��������

# include <stdio.h> 


void QuickSort(int * a, int low, int high);
int FindPos(int * a, int low, int high);

int main(void){
	int a[6] = {-5,2,1,7,-9,3};
	int i;
	
	QuickSort(a,0,5); //����������Ϊa��β��index
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	 
	return 0;
}

void QuickSort(int * a, int low, int high){
	if (low < high){
		// �ҵ���һ��Ԫ�ص�λ�� �� 
		int pos = FindPos(a, low, high); 
		// �ٷֱ�ݹ飺 
		QuickSort(a,low,pos-1);
		QuickSort(a,pos+1,high);
	}
}

int FindPos(int * a, int low, int high){
	int val = a[low];
	while (low<high){
		while (a[high]>=val && low<high)  //ע������low<high����© 
			high--;
		a[low] = a[high];
		
		while (a[low]<=val && low<high)
			low++;
		a[high] = a[low];
	}
	a[low] = val;
	
	return low;
}

