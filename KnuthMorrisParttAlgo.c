/*	Knuth, Morris Pratt Algorithm	*/

#include<stdio.h>
#include<string.h>

int findSubstr(char *str1 , char *str2)
{

/*		CREATING LPS ARRAY		*/

	int lps[strlen(str2)];
	
	lps[0] = 0;
	
	while(j<strlen(str2))												
	{
		if(str2[i] == str2[j])
		{
			lps[j] = i+1;
			i++;
			j++;
		}
		else if(i==0)
		{
			lps[j] = 0;
			j++;
		}
		else
		{
			i = lps[i-1];
		}
	}
	
	i = 0;
	j = 0;
	
/*		FINDING STRING		*/

	while(i<strlen(str1))
	{
		if(str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j==0)
			{
				i++;
			}		
			else
			{
				j = lps[j-1];
			}	
		}
		
		if(j == strlen(str2))
		{
			return (i-j);				// if found then returning the index
		}
	}
	return -1;							// if not found then returning -1
}

int main()
{
	char str1[100];
	char str2[50];
	
	scanf("%s%s",str1,str2);
	
	int i=0,j=1;
	
	int index = findSubstr(str1,str2);
	
	printf("%d\n",index);
}
