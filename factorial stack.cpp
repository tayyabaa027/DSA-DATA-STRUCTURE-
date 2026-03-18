#include<iostream>
using namespace std;
const int size=5;
struct stack
{
   int arr[size];
   int top;
};
void push(stack &s,int v)
{
	s.arr[++s.top]=v;
}
int isempty(stack &s)
{
	if(s.top==-1)
	return 1;
	else 
	return 0;
}
int pop(stack &s)
{
	return s.arr[s.top--];
}
int main()
{
	int f=1;
	stack s;
	s.top=-1;
	for(int i=1;i<=5;i++)
	push(s,i);
	while(!isempty(s))
	{
	f=f*pop(s);
	}
	cout<<"Factorial :"<<f;
	return 0;
}
