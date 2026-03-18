#include<iostream>
using namespace std;
int main()
{

	//SELECTION SORT
	  
	int a[5]={64,25,12,22,11};
	int i,j,temp;
	for(i=0;i<5;i++)
	{
		int s=i;
		for(j=i+1;j<5;j++)
		{
			if(a[s]>a[j])
			{
				temp=a[s];
				a[s]=a[j];
				a[j]=temp;
			}
		}
	}
	cout<<"\n Sorted array:";
	for(i=0;i<5;i++)
	cout<<a[i]<<" ";

	
}
