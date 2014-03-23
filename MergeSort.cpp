#include <iostream>
#include <cstdio>
using namespace std;

int arr[100],aux[100];

void merge(int low,int mid,int high)
{
   for(int i=low;i<=high;i++)
   aux[i] = arr[i];

   int i=low;int j=mid+1;
   for(int k=low;k<=high;k++)
   {
       if(i>mid) arr[k] = aux[j++];
       else if(j>high) arr[k] =aux[i++];
       else if(arr[i]<arr[j]) arr[k] = aux[i++];
       else arr[k] = aux[j++];
   }
}

void sort(int low, int high)
{
    if(high<=low) return;
    int mid = low + (high - low)/2;
    sort(low,mid);
    sort(mid+1,high);
    merge(low,mid,high);
}

int main()
{
    int n;
    printf("How many numbers to sort?\n");
    scanf("%d",&n);

    printf("Enter the numbers?\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    sort(0,n-1);

    printf("\nThe sorted list is: ");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;
}
