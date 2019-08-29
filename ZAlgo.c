#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void findSubstr(char *str1,char *str2)
{
	char * str3 = (char*)malloc(sizeof(char)*strlen(str1)*strlen(str2)+1);		// creating a new string
	
/*	concating string2 and string1 differentiated by "$"	*/

	strcat(str3,str2);		
	strcat(str3,"$");
	strcat(str3,str1);
	
	int Z[str3.length()];													// creating Z-value array
	
	int left = 0,right = 0;
	
	for(int i = 1 ;  i<strlen(str3) ; i++)
	{
		if(i>right)
		{
			left = i;
			right = i;
			while(right < strlen(str3) && str3[right] == str3[right - left]
			{
				right ++;
			}
			Z[i] = right - left;
			right --;
		}
		else
		{
			int k = i - left;
			if(Z[k] + i < right + 1)
			{
				Z[i] = Z[k];										
			}
			else
			{
				while(right<strlen(str3) && str3[right] == str3[right-left])
				{
					right ++;
				}
				Z[i] = right - left;
				right --;
			}
		}
		if(Z[i] == strlen(str2))
		{
			return (i - strlen(str2) - 1);
		}
	}
	return -1;
}

int main()
{
    char str1[100] ,str2[50];
    
    scanf("%s%s",str1,str2);
	
	int index = findSubstr(str1,str2);
	
	printf("%d\n",index);
	
    return 0;
}

