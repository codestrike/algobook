/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Stack using array in C
*/

#include <stdio.h>
#define MAX 20

int stack[MAX];
int top;

void push(int value)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		stack[++top] = value;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		return stack[top--];
	}
}

void display()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		for (int i = 0; i <= top; ++i)
		{
			printf("%d ", stack[i]);
		}
	}
}

int main()
{
	int choice, input;
	top = -1;

	while(1)
	{
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			printf("Enter value to push: ");
			scanf("%d", &input);
			push(input);
			break;

			case 2:
			printf("Value popped: %d\n", pop());
			break;

			case 3: display(); break;

			case 4: return 0;

			default:
			printf("Remember This Program Is Created By Ashish Gaikwad\n");
		}
	}
	return 0;
}