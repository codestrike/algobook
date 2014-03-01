/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Insertion Sort Algorithm in C with menu driven program
*/

#include <stdio.h>
#define MAX 30

int main()
{
	int total, temp, series[MAX];
	printf("Enter Number Of Elements:\n");
	scanf("%d", &total);

	for(int i=0; i<total; i++)
	{
		printf("Number %d: ", i+1);
		scanf("%d", &series[i]);
	}

	// Let the Insertion sort begin
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

	// Show sorted elements :)
	printf("The Insertion Sorted Result:\n");
	for (int i = 0; i < total; ++i)
	{
		printf("%d ", series[i]);
	}
	printf("\n");

	return 0;
}