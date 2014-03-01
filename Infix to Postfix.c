/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Infix expression to Postfix expression convertor program
*/

#include <stdio.h>
#include <string.h>
#define MAX 40

char stack[MAX];
int top;

char pop()
{
	if(top!=-1) return stack[top--];
}

void push(char value)
{
	if(top!=MAX) stack[++top] = value;
}

int is_operator(char value)
{
	switch(value)
	{
		case '+': case '-': case '*':
		case '/': case '^': return 1;
	}
	return 0;
}

int is_bracket(char value)
{
	switch(value)
	{
		case '(': return 1;
		case ')': return 2;
	}
	return 0;
}

int get_priority(char value)
{
	switch(value)
	{
		case '+': case '-': return 1;

		case '*': case '/': return 2;

		case '^': return 3;

		case '(': case ')': return 4;
	}

	return 5;
}

int is_higher(char first, char second)
{
	return get_priority(first) > get_priority(second);
}

int main()
{
	char input[MAX];
	int string_len;
	top = -1;
	push('('); // this is default value of stack[top] (top=0) highest priority

	printf("Enter Infix :\n");
	scanf("%s", input);
	printf("Your Infix is %s and len : %d\n", input, (int)strlen(input));

	string_len = strlen(input);
	input[string_len] = ')';

	for(int i=0; i<string_len && i<20; i++)
	{
		if(is_operator(input[i]))
		{
			if(is_bracket(stack[top])==1 || is_higher(input[i], stack[top]))
			{
				push(input[i]);
			}
			else
			{
				while( !is_bracket(stack[top]))
				{
					printf("%c ", pop());
					if(is_higher(input[i], stack[top])) break;
				}

				push(input[i]);
			}
		}
		else if(is_bracket(input[i]))
		{
			if(is_bracket(input[i])==2)
			{
				while(is_bracket(stack[top])!=1) printf("%c ", pop());

				if(top!=0 && is_bracket(stack[top])==1) pop();
			}
			else 
			{
				push(input[i]);
			}
		}
		else
		{
			printf("%c ", input[i]);
		}
	}

	// Now display remaining elements of stack
	while(top!=0) printf("%c ", pop());

	printf("\n");
	return 0;
}