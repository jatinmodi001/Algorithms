#include<stdio.h>

void swap(int arr[],int a,int b)
{
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

void sink(int arr[],int i,int n)
{
    if(i >= n - 1)          // If i == last element/ size of array then return
        return;

    int max = i;
    int left = 2*i;         // left child of parent
    int right = 2*i + 1;    // right child of parent

    if(left < n && arr[left] > arr[max] )            // Checking if the left child is max than parent or not
    {
        max = left;
    }
    if(right < n && arr[right] > arr[max] )         // Checking if the right child is max than parent or not
    {
        max = right;
    }
    if(i != max)        // if i changes means the parent is smaller than left or right or from both than swap
    {
        swap(arr,i,max);    // swaping initial i with the changed i
        sink(arr,max,n);    // Recursive call for another part
    }
    
}

void Heapify(int arr[],int n)
{
    for(int i = n/2 ; i >= 0 ; i--)
    {
        sink(arr,i,n);
    }
}

void HeapSort(int arr[], int n)
{
    Heapify(arr,n);                     // Converting given array into max heap
    for(int i = n - 1 ; i >=0; i--)
    {
        swap(arr,0,i);                  // swapping the max element to ith
        Heapify(arr,i);                 // Again heapfying the array now from the ith element
    }
}

int main()
{
    int n;
    scanf("%d",&n);             // Scanning size of array

    int arr[n];             
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);       // Scanning elements of array
    }

    HeapSort(arr,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);       // Printing array elements
    }
}