#include<iostream>
using namespace std;

int const size=10;
struct queue
{
	int arr[size];
	int rear;
	int front;
};

int isFull(queue &q)
{
	if(q.rear==size-1)
		return 1;
	else
		return 0;	
}

int isEmpty(queue &q)
{
	if(q.front>q.rear)
		return 1;
	else
		return 0;		
}

void insert_front(queue &q, int v)
{
	if(q.front == 0)
	{
        cout<<"No space at front."<<endl;
	}
    else 
	{
        q.arr[--q.front]=v;
        cout<<v<<" inserted at front."<<endl;
    }
}

int remove_front(queue &q)
{
    if(isEmpty(q))
	{
        cout<<"Queue is empty."<<endl;
        return 1;
    } 
	else 
	{
        int k=q.arr[q.front++];
        return k;
    }
}

void insert_rear(queue &q, int v)
{
	if(isFull(q))
	{
        cout<<"Queue is full."<<endl;
    }
    else
	{
        q.arr[++q.rear]=v;
        cout<<v<<" inserted at rear."<<endl;
    }
}

int remove_rear(queue &q)
{
	if(isEmpty(q))
	{
        cout<<"Queue is empty."<<endl;
        return 1;
    } 
	else 
	{
        int k=q.arr[q.rear--];
        return k;
    }
}

void display(queue &q)
{
	cout<<"Queue is: ";
	for(int i=q.front; i<=q.rear; i++)
	{
		cout<<q.arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	queue q;
	q.front=0;
	q.rear=-1;
	
	do
	{
		cout<<"\nPress 1 for input."<<endl;
		cout<<"Press 2 for output."<<endl;
		cout<<"Press 3 for display."<<endl;
		cout<<"Press 4 for exit."<<endl;
		int num, a;
		char ch, b;
		cin>>num;
		
		switch(num)
		{
			case 1:
				cout<<"-------Input Restricted-------"<<endl;
				cout<<"Press A for insertion."<<endl;
				cout<<"Press B for removal."<<endl;
				cin>>ch;
				
				switch(ch)
				{
					case 'A':
						cout<<"Enter the value: ";
						cin>>a;
						
						insert_rear(q, a);
						break;
						
					case 'B':
						cout<<"Press C for front removal."<<endl;
						cout<<"Press D for rear removal."<<endl;
						cin>>b;
						
						switch(b)
						{
							case 'C':
								cout<<"Value removed from front: "<<remove_front(q)<<endl;
								break;
							
							case 'D':
								cout<<"Value removed from rear: "<<remove_rear(q)<<endl;
								break;
								
							default:
								cout<<"Invalid!"<<endl;
								break;	
						}
						break;
					
					default:
						cout<<"Invalid!"<<endl;
						break;		
				}
				break;
			
			case 2:
				cout<<"-------Output Restricted-------"<<endl;
				cout<<"Press E for insertion."<<endl;
				cout<<"Press F for removal."<<endl;
				cin>>ch;
				
				switch(ch)
				{
					case 'E':
						cout<<"Enter the value: ";
						cin>>a;
						
						cout<<"Press G for front insertion."<<endl;
						cout<<"Press H for rear insertion."<<endl;
						cin>>b;
						
						switch(b)
						{
							case 'G':
								insert_front(q, a);
								break;
								
							case 'H':
								insert_rear(q, a);
								break;
								
							default:
								cout<<"Invalid!"<<endl;
								break;		
						}
						break;
						
					case 'F':
						cout<<"Value removed from front: "<<remove_front(q)<<endl;
						break;
						
					default:
						cout<<"Invalid!"<<endl;
						break;		
				}
				break;
				
			case 3:
				display(q);
				break;
				
			case 4:
				exit(0);
				
			default:
				break;			
		}
	}
	while(true);
	
	return 0;
}
