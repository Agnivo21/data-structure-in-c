/*11)	WAP to convert infix expression to postfix expression.
13)	WAP to convert infix expression to prefix expression.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define MAX 100

int top=-1;
int stack[MAX];

int isfull()
{
	return (top==MAX-1);
}

int isempty()
{
	return (top==-1);
}

void push(char item)
{
	if(isfull() )
		return;
	top+=1;
	stack[top]=item;
}

int pop()
{
	if(isempty() )
		return INT_MIN;
	return stack[top--];
}

int peek()
{
	if(isempty() )
		return INT_MIN;
	return stack[top];
}

int checkifoperand(char ch)
{
	return ((ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z'));
}

int precedence(char ch)
{
	switch(ch)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	}
	return -1;
}

int getPostfix(char *expression)
{
	int i,j;
	for(i=0,j=-1;expression[i];++i)
	{
		if(expression[i]=='(')
			push(expression[i]);
		else if(checkifoperand(expression[i]))
			expression[++j]=expression[i];
		else if(expression[i]==')')
		{
		  while(!isempty() && peek(stack) !='(')
		  	expression[++j]=pop(stack);
		  if(!isempty() && peek(stack)!='(')  //invalid expression peek(stack)=='(' ==> 
		  	return -1;
		  else
		  	pop(stack);
		}
		else
		{
			while(!isempty()&&precedence(expression[i])<=precedence(peek(stack)))
				expression[++j]=pop(stack);
			push(expression[i]);
		}
	}
 
    while(!isempty())
    {
    	expression[++j]=pop(stack);

    }
    expression[++j]='\0';

}

void reverse(char *exp)
{
	strrev(exp);
}

void changebrackets(char *exp)
{
	int i=0;
	while(exp[i] !='\0')
	{
		if(exp[i]=='(')
			exp[i]=')';
		else if(exp[i]==')')
			exp[i]='(';
		i++;
	}
}

void InfixtoPrefix (char *exp)
{

  int size = strlen (exp);

  // reverse string
  reverse (exp);
  //change brackets
  changebrackets(exp);
  //get postfix
  getPostfix (exp);
  // reverse string again
  reverse (exp);
}

int main ()
{
  printf ("The infix is: ");

  char expression[] = "((a/b)+c)-(d+(e*f))";
  printf ("%s\n", expression);
  InfixtoPrefix(expression);

  printf ("The prefix is: ");
  printf ("%s\n", expression);

  return 0;
}


