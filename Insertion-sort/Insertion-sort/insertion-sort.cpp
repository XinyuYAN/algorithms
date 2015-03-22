#include <iostream>
using namespace std;
void insert_sort(int* a,int i);
void merge_sort(int* a,int head,int tail);//分支归并算法
#define NUM 6
int main()
{
	int a[NUM];
	for(int i=0;i<NUM;++i)
		cin >> a[i];
//	insert_sort(a,NUM);
	merge_sort(a,0,NUM-1);
	for(int i=0;i<NUM;++i)
		cout << a[i];
}

void insert_sort(int *a,int i)
{
	int temp=1;
	for(;temp<i;temp++)
		{
			int key=a[temp];//需移动元素
			for(int j=temp-1;j>=0;--j)
				if(key<a[j])
				{
					int m=key;
					a[j+1]=a[j];
					a[j]=m;
				}
		}
}
void Merge(int *a,int head,int p,int tail)
{
	int n1=p-head+1;//数组1的长度
	int n2=tail-p;//数组2的长度
	int left[20],right[20];
	int i;
	for(i=0;i<n1;i++)
		left[i]=a[head+i];//这里要考虑实际a的位置
	for(i=0;i<n2;i++)
		right[i]=a[p+i+1];
	left[n1]=6220;//定义哨兵项
	right[n2]=7220;
	int j=0;
	i=0;
	for(int k=head;k<=tail;k++)//如果一项已经拷贝完，只需要将另一数组中所有内容拷贝，则使用哨兵项
		if (left[i]<right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
}
void merge_sort(int* a,int head,int tail)
{
	if (head<tail)
	{
		int p= (head+tail)/2;//vs应该会自动取整的吧？
		merge_sort(a,head,p);
		merge_sort(a,p+1,tail);
		Merge(a,head,p,tail);
	}
}