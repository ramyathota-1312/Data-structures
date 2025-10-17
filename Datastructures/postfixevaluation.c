#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 20
void push(int);
int pop();
int peek();
int evaluation_of_postfix(char *);
int Stack[MAX],top=-1;
void push(int n)
{
	Stack[++top]=n;
}
int pop()
{
	return Stack[top--];
}
int peek()
{
	return Stack[top];
}
int evaluation_of_postfix(char *ex)
{
	int dig=0,op=0,i;
	for(i=0;ex[i]!='\0';i++)
	{
		if(isdigit(ex[i]))
		 dig++;
		else if(ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%'||ex[i]=='^')
		 op++;
	}
	if(dig<=op)
	{
		printf("Invalid expression\n");
		exit(0);
	}
	for(i=0;ex[i]!='\0';i++)
	{
		if(isdigit(ex[i])||ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%')
		{
			if(isdigit(ex[i]))
			 push(ex[i]-'0');
			else
			{
				int x1,x2;
				x1=pop();
				x2=pop();
				switch(ex[i])
				{
					case '+':push(x2+x1);break;
					case '-':push(x2-x1);break;
					case '*':push(x2*x1);break;
					case '/':push(x2/x1);break;
					case '%':push(x2%x1);break;
				}
			}
		}
		else
	     {
	     	printf("Invalid expression\n");
	     	exit(0);
		 }
	}
	if(top!=0)
	{
		printf("Invalid expression\n");
		exit(0);
	}
	else 
	{
		return Stack[top];
	}
}
int main()
{
	char postfix[MAX];
	int result;
	printf("Enter a valid postfix expression:");
	gets(postfix);
	result=evaluation_of_postfix(postfix);
	printf("Result of postfix evaluation is %d\n",result);
	return 0;
}
