#include<iostream>
#include<string>
using namespace std;
const int size=5;
struct book
{
	int id;
	string name;
	int price;
	
};
struct stack
{
	book arr[size];
	int top;
	
};
void push( stack &s,book b)
{
	s.arr[++s.top]=b;
//	s.arr[s.top].name=b.name;
//	s.arr[s.top].price=b.price;
}
book pop(stack &s)
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
void display(stack s)
{
	for (int i=0;i<=s.top;i++)
	cout<<s.arr[i].id<<" "<<s.arr[i].name<<" "<<s.arr[i].price<<endl;
}

int main()
{
	book b;
	stack s;
	s.top=-1;
	int v;
	char v;
	do
	{
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"ENTER CHOICE:";
		cin>>choice;
		switch(choice)
		{
			case '1':
			if(isfull(s))
			cout<<"\nSTACK FULL";
			else
			{
			
			cout<<"\nEnter id name price:";
			cin>>b.id>>b.name>>b.price;
			push(s,b);
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
				cout<<"\nSTACK:"<<endl;
				display(s);
			}
				break;
			default:cout<<"\n INVALID CHOICE";
		}
		cout<<"\n CONTINUE PRESS 1  ELSE 0:";
		cin>>choice;
	}while(choice=='1');
	
	return 0;
}
	
	
	
	


