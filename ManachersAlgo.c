#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* LongestPalindromeSubstring(char str[])
{
	char *res = (char*)malloc(sizeof(char)*strlen(str));
	
    int i=0,j=0, size = 2*strlen(str)+1;
    
    /* creating a new string of size double of original size + 1
       in this string we include '$' in between every character
       so as to remove even substrings			*/
        
    char newstr[size];		
    for(i=0;i<size;i++)
    {
        if(i%2 == 0)
        {
            newstr[i]='$';	
        }
        else
        {
            newstr[i] = str[j++];
        }
    }
    int *arr = (int *)malloc(sizeof(int)*size);		// creating LPS length array
    
    int l=0,r=0,max = 1;
    int start = 0,end = 1;
    arr[0] = 1;			// as first character will have LPS length 1 so initialize arr[0] with 1
    i=1;			// start from 2nd character
    
    while(i<size)
    {
        if(i>=r)
        {
            r = i + 1;
            l = i - 1;
            while(l>=0 && r<size && (newstr[r] == newstr[l]))
            {
                r++;
                l--;
            }
            arr[i] = r-l+1;			// length of palindromic string
            
            if(arr[i] > max)		// if length is max then replacing start and end with new index values
            {
                max = arr[i];
                start = l+1;
                end = r;
            }
            l = i-1;
        }
        else
        {
            if((i+arr[l]/2+1) < r)		// used to copy previous elements
            {
                arr[i] = arr[l];
                l--;
            }
            else
            {
                r = i;
                continue;
            }
        }
        i++;
    }
    j=0;
    for(i=start;i<end;i++)		// copying longest palidrome to res
    {
        if(newstr[i]!='$')
            res[j++] = newstr[i];
    }
    res[j] = '\0';
    return res;	
    
}
int main()
{
    char str[100];
    scanf("%s",str);             // scanning string
    char *substr = LongestPalindromeSubstring(str);
    printf("%s\n",substr);
}
