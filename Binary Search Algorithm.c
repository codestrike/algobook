/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Binary Search Algorithm in C with menu driven program
*/

#include <stdio.h>
#define MAX 30

int series[MAX];

int main()
{
	int start, mid, end;
	int total, input, temp;

	printf("Enter number of values : ");
	scanf("%d", &total);

	for (int i = 0; i < total; ++i)
	{
		printf("Enter value %d : ", i+1);
		scanf("%d", &series[i]);
	}

	//  Sort the input using Insertion sort
	for (int i = 0; i < total; ++i)
	{
		for (int j = i-1; j >= 0; --j)
		{
			if(series[j] > series[j+1])
			{
				temp = series[j];
				series[j] = series[j+1];
				series[j+1] = temp;
			}
			else break;
		}
	}

	printf("Enter value to search : ");
	scanf("%d", &input);

	// Let the Binary Search begin
	start = 0;
	end = total - 1;

	while(start <= end)
	{
		mid = (start + end)/2;

		if(input == series[mid])
		{
			printf("Value %d is found at index %d\n", input, mid);
			return 0;
		}
		else if(input < series[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	printf("Value %d not found\n", input);

	return 0;
}