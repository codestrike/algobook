/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Double Ended Queue 'deque' in C with menu driven program.
*/

#include <stdio.h>
#define MAX 10

int deque[MAX];
int front;
int rear;

void push_front(int value)
{
	if( front == -1 )
	{
		printf("Deque front is full\n");
		return;
	}
	else
	{
		deque[--front] = value;
	}
}

int pop_front()
{
	if( front==rear )
	{
		printf("Deque front is Empty\n");
		return -1;
	}
	else
	{
		return deque[++front];
	}
}

void push_back(int value)
{
	if( rear == MAX )
	{
		printf("Deque is full\n");
		return;
	}
	else
	{
		deque[rear++] = value;
	}
}

int pop_back()
{
	if( rear == front )
	{
		printf("Deque is empty\n");
		return -1;
	}
	else
	{
		return deque[--rear];
	}
}

void display()
{
	for(int i=front; i<rear; i++)
		printf("%d ", deque[i]);
	printf("\n");
}

int main()
{
	int choice, input;
	front = rear = MAX/2;

	while(1)
	{
		printf("\n1. Insert Front\n2. Insert Back\n3. Delete Front\n4. Delete Back\n5. Display\n6. Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			printf("Enter valued to insert front:\n");
			scanf("%d", &input);
			push_front(input);
			break;

			case 2:
			printf("Enter valued to insert back:\n");
			scanf("%d", &input);
			push_back(input);
			break;

			case 3:
			printf("Valued to deleted front: %d\n", pop_front());
			break;

			case 4:
			printf("Valued to deleted back: %d\n", pop_back());
			break;

			case 5: display(); break;
			case 6: return 0;

			default:
			printf("Remember this program is created by Ashish Gaikwad\n");
		}
	}

	return 0;
}