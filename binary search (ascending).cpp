#include<iostream>
using namespace std;
int main()
{
	const int size=5;
	int a[size]={12,45,67,68,78};
	int flag=0,i,index,v;
	int low=0,mid,high=size-1;
	cout<<"\nEnter number to find:";
	cin>>v;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(v==a[mid])
		{
			flag=1;
			index=mid;
			break;
		}
		else if(v>a[mid])
		low=mid+1;
		else
		high=mid-1;
	}
	if(flag==1)
	cout<<"found "<<v<<" at index"<<index;
	else
	cout<<"\n not found";
	return 0;
}
