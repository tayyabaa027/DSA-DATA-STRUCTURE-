#include<iostream>
using namespace std;
const int size=5;
struct stack
{
	int arr[size];
	int top;
	
};
void push( stack &s,int v)
{
	s.arr[++s.top]=v;
}
int pop(stack &s)
{
	return s.arr[s.top--];
}
int isfull(stack &s)
{
	if (s.top==size-1)
	return 1;
	else 
	return 0;
}
int isempty(stack &s)
{
	if (s.top==-1)
	return 1;
	else 
	return 0;
}
void deletemid(stack &s)
{
	
	if (isempty(s))
	{
	cout<<"\n STACK IS EMPTY";
	return;
}
int mid=s.top/2;
stack temp;
temp.top=-1;
int m=s.top-mid;
for(int i=0;i<m;i++)
push(temp,pop(s));
int midv=pop(s);
cout<<"\n mid value is :"<<midv;
while(!isempty(temp))
push(s,pop(temp));

}
void display(stack s)
{
	for (int i=0;i<=s.top;i++)
	cout<<s.arr[i]<<"   ";
}

int main()
{
	stack s;
	s.top=-1;
	int v;
	char choice;
	do
	{
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4. deletemid"<<endl;
		cout<<"ENTER CHOICE:";
		cin>>choice;
		switch(choice)
		{
			case '1':
			if(isfull(s))
			cout<<"\nSTACK FULL";
			else
			{
			
			cout<<"\nEnter value to insert";
			cin>>v;
			push(s,v);
		    }
	     	break;
			
			case '2':
			if(isempty(s))
			cout<<"\nSTACK EMPTY";
			else
			pop(s);
			break;
			case '3':
					if(isempty(s))
			cout<<"\nSTACK EMPTY";
			else
			{
				cout<<"\nSTACK:";
				display(s);
			}
			break;
			case '4': deletemid(s);
			break;
			default:cout<<"\n INVALID CHOICE";
		}
		cout<<"\n CONTINUE PRESS 1  ELSE 0";
		cin>>choice;
	}while(choice=='1');
	
	return 0;
}
	
	
	
	


