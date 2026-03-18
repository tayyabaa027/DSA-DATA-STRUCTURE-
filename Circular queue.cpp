#include<iostream>
using namespace std;
int Rcount=0;
int Fcount=0;
const int size=5;
struct queue
{
	int arr[size];
	int r;
	int f;
};
void insert(queue &q,int v)
{
	if(q.r==size-1)
	{
		Rcount++;
		q.r=-1;
	}
	q.arr[++q.r]=v;
	
}
int isfull(queue &q)
{
	if(Rcount==Fcount)
	{
		if (q.f==0 && q.r==size-1)
		return 1;
		else 
		return 0;
	}
	else
	{
	if(q.f==q.r+1)
	return 1;
	else 
	return 0;
}
	
}
int remove(queue &q)
{
 int r=q.arr[q.f];
 if(q.f==size-1)
 {
 	Fcount++;
 	q.f=0;
 }
 else
 q.f++;
 return r;
	
}
int isempty(queue &q)
{
	if(Rcount==Fcount)
	{
		if(q.f>q.r)
		return 1;
		else 
		return 0;
	}
	else
	if(q.r==-1 && q.f==0)
	return 1;
	else
	return 0;
	
}
void display(queue &q)
{
    if(isempty(q))
    {
        cout << "\nQueue is empty!";
        return;
    }

    cout << "\nQUEUE: ";
    int i = q.f;                  // start from front
    while (true)
    {
        cout << q.arr[i] << " ";  // print current element
        if (i == q.r)             // if we reached rear, stop
            break;
        i = (i + 1) % size;       // move to next index (circular)
    }
}

int main()
{ 
    int n;
	queue q;
	q.f=0;
	q.r=-1;
   int choice;
	do{
	cout<<"1. INSERT"<<endl;
	cout<<"2. REMOVE  "<<endl;
	cout<<"3. DISPLAY"<<endl;
	cout<<"Enter choice:";
	cin>>choice;
	switch(choice)
	{
		case 1: if(isfull(q))
		          cout<<"\nQUEUE FULL";
		          else
		          {
		          	cout<<"\nEnter number:";
		          	cin>>n;
		          	insert(q,n);
		          	
				  }
				  break;
	   case 2: if(isempty(q))
		          cout<<"\nQUEUE empty";
		          else
		          {
		          	remove(q);
		          	
				  }
				  break;
      case 3: display(q);
      break;
      default:
      	cout<<"\n Invalid choice";
	}
	cout<<"\nDo you want to continue press 1 else 0"<<endl;
	cin>>choice;
}while(choice==1);
return 0;
}













