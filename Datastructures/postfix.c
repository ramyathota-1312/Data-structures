#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 20
int top=-1;
int stack[SIZE];
int precedence(char);
void push(char);
char pop();
char peek();
void infix_to_postfix(char*);
int precedence(char ch)
{
	switch(ch)
	{
		case '+':
			case '-':return 1;
			case '*':
				case '/':
				case '%':return 2;
				case '^':return 3;
				default:return 0;
	}
}
void push(char ch)
{
	top++;
	stack[top]=ch;
}
char pop()
{
	return stack[top--];
}
char peek()
{
	return stack[top];
}
void infix_to_postfix(char *ex)
{
	char postfix[SIZE];
	int i,j=0;
	for(i=0;ex[i]!='\0';i++)
	{
		if(ex[i]=='('||ex[i]==')'||isalnum(ex[i])||ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%'||ex[i]=='^')
		{
			if(isalnum(ex[i]))
			postfix[j++]=ex[i];
			else if(ex[i]=='(')
			push(ex[i]);
			else if(ex[i]==')')
			{
				while(top!=-1&&peek()!='(')
				postfix[j++]=pop();
				if(top==-1)
				{
					printf("Invalid expression\n");
					exit(0);
				}
				pop();
			}
			else
			{
				while(top!=-1&&precedence(peek())>=precedence(ex[i]))
				{
					postfix[j++]=pop();
				}
				push(ex[i]);
			}
		}
		else
		{
			printf("Invalid expression\n");
			exit(0);
		}
	}
	while(top!=-1)
	{
		char ch=pop();
		if(ch=='(')
		{
			printf("Invalid expression\n");
			exit(0);
		}
		postfix[j++]=ch;
	}
	postfix[j]='\0';
	printf("Postfix expression is %s\n",postfix);
}
int main()
{
	char infix[SIZE];
	printf("Enter a valid expression: ");
	gets(infix);
	infix_to_postfix(infix);
	return 0;
}
