#include<iostream>
using namespace std;
const int size=5;
int binarysearch(int arr[],int n)
{
	int mid,low=0,high=size-1;
	int index;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(n==arr[mid])
		{
			cout<<"\n value"<<n<<" found at index "<<mid;
			return 1;
		}
		else if(n>arr[mid])
		high=mid-1;
		else
		low=mid+1;
	}
	return -1;
}
int main()
{
	
	int v,a[size]={46,45,23,22,12};
	cout<<"\nEnter number to find";
	cin>>v;
	int i=binarysearch(a,v);
	if(i==-1)
	cout<<"\n not found";
	return 0;
}
