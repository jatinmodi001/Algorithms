#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int mid,int r)
{
    int i,j,k;
    int size1 = mid - l + 1;        // size of first half
    int size2 = r - mid;            // size of second half

    int left[size1];       // Declaring temporary array for first half
    int right[size2];      // Declaring temporary array for second half
    
    for(i=0;i<size1;i++)
    {
        left[i] = arr[l+i];         // copying elements
    }

    for(j=0;j<size2;j++)
    {
        right[j] = arr[mid+1+j];    // copying elements
    }

    i = j = 0 ; k = l;

    while(i<size1 && j<size2)
    {
        if(left[i] < right[j])          // if the element of left is smaller than right
        {
            arr[k++] = left[i++];       // copying smaller element to main array
        }
        else
        {
            arr[k++] = right[j++];
        }
    }  

/*       Adding remaining elements        */

    while(i < size1)
    {
        arr[k++] = left[i++];
    }
    while(j < size2)
    {   
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[],int l,int r)
{
    if(l<r)                 // if more than 1 element
    {
        int mid = (l + r)/2;
        mergeSort(arr,l,mid);       // for first half
        mergeSort(arr,mid+1,r);     // fir second half
        merge(arr,l,mid,r);
    }
}

int main()
{
    int n;
    scanf("%d",&n);         // Size of array

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);       // Scanning element
    }

    mergeSort(arr,0,n-1);       

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);       // printing elements
    }
    return 0;
}