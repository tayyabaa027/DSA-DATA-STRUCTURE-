#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
const int size=15;
struct stack
{
	double items[size];
	int top;
};
void push(stack &s,double v)
{
	s.items[++s.top]=v;
	
}
double pop(stack &s)
{
	return s.items[s.top--];
}
void display(stack &s)
{
	cout<<"The Result of Expression is="<<s.items[s.top];
}
double operation(double op1,double op2,char sym)
{
	switch(sym)
	{
		case '+': return op1+op2;
		break;
		case '-':return op1-op2;
		break;
		case '*':return op1*op2;
		break;
		case '/':return op1/op2;
		break;
		case '$':return pow(op1,op2);
		break;
		default: return 0;
	}
}
void postfixevaluation(char exp[30])
{
	stack s;
	s.top=-1;
	char sym;
	for (int i=0;i<strlen(exp);i++)
	{
		sym=exp[i];
		if(sym>='0' && sym<='9')
		push(s,sym-'0');
		else if( sym=='+'||sym=='-'||sym=='*'||sym=='/'||sym=='$')
		{
			double op2=pop(s);
			double op1=pop(s);
			double value=operation(op1,op2,sym);
			push(s,value);
		}
		else
		cout<<"\n invalid";
		
	}
	display(s);
}
int main()
{
	char exp[30];
	cout<<"\nEnter expression:";
	cin>>exp;
	postfixevaluation(exp);
	return 0;
}
