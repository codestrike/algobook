/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Binary Search Tree in C with menu driven program.
*/

#include <stdio.h>
#include <stdlib.h>

// Basic structure of a single node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};

// function to search a node by value
int search(struct Node *n, int value)
{
	if(!n) return 0;
	if( n->key==value ) return n->key;
	if( value < n->key ) return search(n->left, value);
	else return search(n->right, value);
}

// Traversal functions
// Inorder : LVR
void traverse_inorder(struct Node *n)
{
	if ( n!=NULL )
	{
		traverse_inorder(n->left);
		printf("%d ", n->key);
		traverse_inorder(n->right);
	}
	return;
}

// Preorder : VLR
void traverse_preorder(struct Node *n)
{
	if ( n!=NULL )
	{
		printf("%d ", n->key);
		traverse_preorder(n->left);
		traverse_preorder(n->right);
	}
	return;
}

// Postorder : LRV
void traverse_postorder(struct Node *n)
{
	if ( n!=NULL )
	{
		traverse_postorder(n->left);
		traverse_postorder(n->right);
		printf("%d ", n->key);
	}
	return;
}

// function to insert a node
struct Node* insert(struct Node *n, int value) {
	if( n==NULL ) 
	{
	// this is like 'new' operator of C++ :)
		struct Node *tmp = (struct Node *) malloc(sizeof(struct Node));
	// Now lets do what constructor does in C++
		tmp->left = tmp->right = NULL;
		tmp->key = value;
		return tmp;
	}
	else if (value < (n->key)) {
		n->left = insert(n->left, value);
	}
    else if(value > (n->key))
    {
        n->right = insert(n->right, value);
    }
    return n;
}

struct Node* find_min(struct Node *n)
{
	if( n==NULL ) return n;
	if( n->left ) return find_min(n->left);
	else return n;
}

// function to delete a node by value
struct Node* delete(int value, struct Node *n)
{
	struct Node *to_delete = NULL;
	
	if( n==NULL ) printf("Node with value %d not found\n", value);
	else if( value < n->key ) n->left = delete(value, n->left);
	else if( value > n->key ) n->right = delete(value, n->right);
	
	else if( n->key == value )
	{
		if(n->left && n->right)
		{
			to_delete = find_min(n->right);
			n->key = to_delete->key;
			n->right = delete(to_delete->key, n->right);
		}
		else
		{
			to_delete = n;
			if(n->left == NULL) n = n->right;
			else if(n->right == NULL) n = n->left;
            free(to_delete);
		}
	}
	return n;
}

int main()
{
	int i, input=0, choice=0, num;
	struct Node* root = NULL;

	while(1){
		printf("\nEnter Your Choice:\n");
		printf("1. Insert\n2. Display\n3. Delete\n4. Search\n5. Exit\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
			printf("How many elements ?\n");
			scanf("%d", &num);
			for(i=1; i<=num; i++)
			{
				printf("Enter %d :", i);
				scanf("%d", &input);
				root = insert(root, input);
			}
			break;

			case 2:
			printf("In which order\n");
			printf("1. Pre-Order\n2. In-Order\n3. Post-Order\n");
			scanf("%d", &input);
			switch(input)
			{
				case 1: traverse_preorder(root); break;
				case 2: traverse_inorder(root); break;
				case 3: traverse_postorder(root); break;
			}
			break;

			case 3:
			printf("Enter value to delete\n");
			scanf("%d", &input);
			delete(input, root);
			break;

			case 4:
			printf("Enter value to search\n");
			scanf("%d", &input);
			if(search(root, input)!=0) printf("Value is found\n");
			else printf("Value is not found\n");
			break;

			case 5: return;

			default:
			printf("Remember this program is written by Ashish Gaikwad\n");
		}
	}
}