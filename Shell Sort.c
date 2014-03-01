/**
* @author: Ashish A Gaikwad <ash.gkwd@gmail.com>
* Shell Sort Algorithm (modified Insertion sort) in C
*/

#include <stdio.h>
#define MAX 30

int main()
{
	int total, kira, series[MAX];
	printf("Enter Number Of Elements:\n");
	scanf("%d", &total);

	for(int i=0; i<total; i++)
	{
		printf("Number %d: ", i+1);
		scanf("%d", &series[i]);
	}

	
	for (int i = total/2; i>0; --i)
	{
		// Let the Partial Insertion sort begin
		for(int z = i; z<total; z++)
		{
			for (int j = z-1; j>=0; j -= i)
			{
				if(series[j] > series[j+i])
				{
					kira = series[j];
					series[j] = series[j+i];
					series[j+i] = kira;
				}
				else break;
			}
		}
	}

	// Show sorted elements :)
	printf("The Shell Sorted Result:\n");
	for (int i = 0; i < total; ++i)
	{
		printf("%d ", series[i]);
	}
	printf("\n");

	return 0;
}