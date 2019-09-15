#include<stdio.h>
void swap(int arr[],int a,int b)
{
	int c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}
void quickSort(int arr[],int l,int r)			// Taking 1st element as pivot
{
	if(l>=r)
		return;
		
	int last = l;
	
	for(int i=l+1;i<=r;i++)
	{
		if(arr[i] < arr[l])
		{
			swap(arr,i,++last);		// swapping all the elements which are smaller than pivot
		}
	}
	swap(arr,last,l);				// moving pivot to its correct position
	quickSort(arr,l,last-1);
	quickSort(arr,last+1,r);  
}
int main()
{
	int n;
	scanf("%d",&n);			// Size of arrays
	
	int arr[n];				// Declaring array
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);		// Scanning elements of array
	}
	
	quickSort(arr,0,n-1);
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);		// Printing array
	}
}
