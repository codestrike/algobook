/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Linked List in C with menu driven program
*/

#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
	int data;
	struct LinkedList *next;
} *start;

void insert_after(int value, int after)
{
	struct LinkedList * iter = start;
	struct LinkedList * to_insert = (struct LinkedList*) malloc(sizeof(struct LinkedList));

	while(iter->data!=after)
	{
		if(iter->next!=NULL) iter = iter->next;
		else return;
	}

	to_insert->data = value;
	to_insert->next = iter->next;
	iter->next = to_insert;
}

void insert_beginning(int value)
{
	struct LinkedList * to_insert = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	to_insert->data = value;

	to_insert->next = start->next;
	start->next = to_insert;
}

void remove_at(int value)
{
	struct LinkedList * iter = start;
	struct LinkedList * prev = iter;

	while(iter->data!=value)
	{
		prev = iter;
		if(iter->next!=NULL) iter = iter->next;
		else break;
	}

	prev->next = iter->next;
	iter->next = NULL;
	free(iter);
}

void display()
{
	struct LinkedList * iter = start->next;
	while(iter!=NULL)
	{
		printf("%d ", iter->data);
		iter = iter->next;
	}
}

int main(int argc, char const *argv[])
{
	int choice, input, after;
	
	start = (struct LinkedList*) malloc(sizeof(struct LinkedList));
	start->data = 0;
	start->next = NULL;

	while(1)
	{
		printf("\n1. Insert Beginning\n2. Insert After\n3. Remove \n4. Display\n5. Exit");
		printf("\nEnter Your Choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			printf("Enter value to insert : ");
			scanf("%d", &input);
			insert_beginning(input);
			break;

			case 2:
			printf("Enter value to insert : ");
			scanf("%d", &input);
			printf("Insert %d after : ", input);
			scanf("%d", &after);
			insert_after(input, after);
			break;

			case 3:
			printf("Enter value to be removed : ");
			scanf("%d", &input);
			remove_at(input);
			break;

			case 4: display(); break;

			case 5: return 0;

			default:
			printf("Remember This Program Is Created By Ashish Gaikwad\n");
		}
	}
	return 0;
}