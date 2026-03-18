#include<iostream>
using namespace std;
const int size=5;
struct queue
{
	int arr[size];
	int rear;
	int front;
	
};
void  insert(queue &q,int n)
{
	q.arr[++q.rear]=n;
}
int remove(queue &q)
{
	int remove= q.arr[q.front];
	  for (int i = 0; i < q.rear; i++) {
            q.arr[i] = q.arr[i + 1];
        }
        q.rear--; 
        cout<<"deleted value";
        return remove;
}

int isempty(queue &q)
{
	if(q.rear==-1)
	return 1;
	else 
	return 0;
}
int isfull(queue &q)
{
	if(q.rear==size-1)
	return 1;
	else 
	return 0;
}

void display(queue &q)
{
	cout<<"\n QUEUE :";
	for(int i=0;i<=q.rear;i++)
	cout<<q.arr[i]<<" ";
}

int main()
{
	queue q1;
	q1.rear=-1;
	q1.front=0;
	int n;
	int choice;
	do
	{
		cout<<"1. INSERT"<<endl;
		cout<<"2. REMOVE"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"ENTER CHOICE:";
		cin>>choice;
		switch(choice)
		{
			case 1:
			if(isfull(q1))
			cout<<"\nQUEUE FULL";
			else
			{
			
			cout<<"\nEnter Value:";
			cin>>n;
			insert(q1,n);
		    }
	     	break;
			
			case 2:
			if(isempty(q1))
			cout<<"\nQUEUE EMPTY";
			else
			remove(q1);
			break;
			case 3:
				if(isempty(q1))
			cout<<"\nQUEUE EMPTY";
			else
			{
		
				display(q1);
			}
				break;
			default:cout<<"\n INVALID CHOICE";
		}
		cout<<"\n CONTINUE PRESS 1  ELSE 0:";
		cin>>choice;
	}while(choice==1);
	
	return 0;
}

