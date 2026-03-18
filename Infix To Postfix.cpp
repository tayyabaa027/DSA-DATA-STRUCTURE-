#include<iostream>
#include<string.h>
using namespace std;
const int size=20;
struct stack
{
	char arr[size];
	int top;
};
void push(stack &s,char v)
{
	s.arr[++s.top]=v;
}
char pop(stack &s)
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
void display(stack &s)
{
	for (int i=0;i<=s.top;i++)
	cout<<s.arr[i]<<" ";
}
int validity(char expr[30])
{
	stack s1;
	s1.top=-1;
	char sym ;
	bool valid=true;
	for(int i=0;i<strlen(expr);i++)
	{
		sym=expr[i];
		if(sym=='(')
		push(s1,sym);
		else if (sym==')')
		{
			if (isempty(s1))
			{
			valid=false;
			break;
			}
			pop(s1);
		}
	}
	if (!isempty(s1))
	valid=false;
	if (valid)
	{
		cout<<"Expression is valid";
		return 1;
	}
	else
	{
	
	cout<<"Expression is not valid";
	return 0;
}
}
char stacktop(stack &s)
{
	return s.arr[s.top];
}
int precedence(char op) {
    if(op == '^')
	 return 3;
    else if(op == '*' || op == '/') 
	return 2;
    else if(op == '+' || op == '-') 
	return 1;
	else
    return 0;
}

void  infixtopostfix(stack &s,char exp[30])
{
	stack temp ;
	temp.top=-1;
	char sym;
	for(int i=0;i<strlen(exp);i++)
	{
		sym=exp[i];
		if (sym=='(')
		push (temp,sym);
		else if((sym>='a'&& sym<='z') || (sym>='A'&& sym<='Z'))
		push(s,sym);
		else if(sym==')')
		{
			while(stacktop(temp)!='(')
			{
				push(s,pop(temp));
			}
			pop(temp);
		}
		else //operators
		{
			while(!isempty(temp) && precedence(stacktop(temp))>=precedence(sym))
			{
				push(s,pop(temp));
			}
			push(temp,sym);
		}
	}
	while(!isempty(temp))
	push(s,pop(temp));
	cout<<"\nfinally converted"<<endl;
	display(s);
}
string expression(stack &s)
{
	stack temp;
	temp.top=-1;
	while(!isempty(s))
	{
		push(temp,pop(s));
	}
	string s1;
	while(!isempty(temp))
	{
		s1+=pop(temp);
	}
	cout<<"EXPRESSION IS:"<<s1;
	return s1;
}
int main()
{
	char exp[30];
	stack s;
	s.top=-1;
	char v;
	string s2;
    cout<<"\nEnter expression:";
    cin>>exp;
	char choice;
	do
	{
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4. VALIDITY"<<endl;
		cout<<"5. INFIX TO POSTFIX"<<endl;
		cout<<"6. WRITE POSTFIX IN EXP FROM STACk";
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
			case '4': 
			validity(exp);
			break;
			case '5':
				if(validity(exp))
				{
					infixtopostfix(s,exp);
				}
			break;
			case '6':
			s2=	expression(s);
				break;
			default:
			cout<<"\n INVALID CHOICE";
		}
		cout<<"\n CONTINUE PRESS y ELSE anything:";
		cin>>choice;
	}while(choice=='y');
	
	return 0;	}
