/*
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Heap sort implementation in C with menu driven program
* Ref: http://www.youtube.com/watch?v=W81Qzuz4qH0
*/

#include "stdio.h"
#define MAX 30

void shift_up(int arr[], int size)
{
	int index = size - 1;
	while( index > 0 )
	{
		int parent = (index-1)/2;
		if( arr[index] > arr[parent] )
		{
			int tmp = arr[index];
			arr[index] = arr[parent];
			arr[parent] = tmp;

			index = parent;
		}
		else
		{
			break;
		}
	}
}

void shift_down(int arr[], int size)
{
	int index = 0;
	int left = 2*index + 1;
	while( left < size )
	{
		int max = left;
		int right = left + 1;
		if( right < size )
		{
			if( arr[right] > arr[left] )
			{
				max++;
			}
		}

		if( arr[index] < arr[max] )
		{
			int temp = arr[index];
			arr[index] = arr[max];
			arr[max] = temp;

			index = max;
			left = 2*index + 1;
		}
		else
		{
			break;
		}
	}
}

void heap_sort(int arr[], int size)
{
	int sorted[MAX];
	int size_backup = size;

	while( size > 0 )
	{
		sorted[size-1] = arr[0];
		arr[0] = arr[size-1];
		size--;
		shift_down(arr, size);
	}

	for (int i = 0; i < size_backup; ++i)
	{
		arr[i] = sorted[i];
	}
}

int main()
{
	int arr[MAX];
	int size;

	printf("Enter Number Of Elements : ");
	scanf("%d", &size);

	printf("Enter values of elements : ");
	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &arr[i]);
		shift_up(arr, i+1);
	}
	
	heap_sort(arr, size);

	printf("Sorted elements :\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	return 0;
}