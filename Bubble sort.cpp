#include<iostream>
using namespace std;
int main()
{
	//BUBBLE SORT
	int a[7]={2,4,5,7,1,0,3};
	int i,j,temp;
	for(i=0;i<7;i++)
	{
		for(j=0;j<(7-1)-i;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"\n Sorted array:";
	for(i=0;i<7;i++)
	cout<<a[i]<<" ";
}
