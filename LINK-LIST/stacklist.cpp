#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class stacklist
{
	node *top;
	public:
		stacklist()
		{
			top=NULL;
		}
		void push(int x)
		{
			node *ptr=new node;
			ptr->data=x;
			ptr->next=top;
			top=ptr;
		}
		int pop()
		{
			if(top==NULL)
			cout<<"EMPTY";
			int T=top->data;
			node *temp=top;
			top=top->next;
			delete temp;
			return T;
		}
		void display()
		{
			node *temp=top;
			if(top==NULL)
			{
				cout<<"\nEMPTY";
			}
		do
			{
				
				cout<<temp->data<<" ";
				temp=temp->next;
				
			}	while(!temp->next==NULL);
		}
};
int main()
{
	stacklist s;
	int choice;
	do
	{
		cout<<"\n1 .push";
		cout<<"\n2 .pop";
		cout<<"\n3 .display";
		cout<<"\nEnter choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:int v;
			cout<<"enter value:";
			cin>>v;
			s.push(v);
			break;
			case 2:s.pop();
			break;
			case 3: s.display();
			break;
			
		}
		cout<<"\n Continue press 1 else 0:";
		cin>>choice;
	}while(choice==1);
	
	return 0;
	
}
