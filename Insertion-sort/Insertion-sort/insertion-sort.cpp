#include <iostream>
using namespace std;
void insert_sort(int* a,int i);
#define NUM 6
int main()
{
	int a[NUM];
	for(int i=0;i<NUM;++i)
		cin >> a[i];
	insert_sort(a,NUM);
	for(int i=0;i<NUM;++i)
		cout << a[i];
}

void insert_sort(int *a,int i)
{
	int temp=1;
	for(;temp<i;temp++)
		{
			int key=a[temp];//ÐèÒÆ¶¯ÔªËØ
			for(int j=temp-1;j>=0;--j)
				if(key<a[j])
				{
					int m=key;
					a[j+1]=a[j];
					a[j]=m;
				}
		}
}