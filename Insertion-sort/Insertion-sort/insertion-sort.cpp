#include <iostream>
using namespace std;
void insert_sort(int* a,int i);
void merge_sort(int* a,int head,int tail);//��֧�鲢�㷨
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
			int key=a[temp];//���ƶ�Ԫ��
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
	int n1=p-head+1;//����1�ĳ���
	int n2=tail-p;//����2�ĳ���
	int left[20],right[20];
	int i;
	for(i=0;i<n1;i++)
		left[i]=a[head+i];//����Ҫ����ʵ��a��λ��
	for(i=0;i<n2;i++)
		right[i]=a[p+i+1];
	left[n1]=6220;//�����ڱ���
	right[n2]=7220;
	int j=0;
	i=0;
	for(int k=head;k<=tail;k++)//���һ���Ѿ������ֻ꣬��Ҫ����һ�������������ݿ�������ʹ���ڱ���
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
		int p= (head+tail)/2;//vsӦ�û��Զ�ȡ���İɣ�
		merge_sort(a,head,p);
		merge_sort(a,p+1,tail);
		Merge(a,head,p,tail);
	}
}