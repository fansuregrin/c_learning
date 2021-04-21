/******************************************************************************
author: fansuregrin
time: 2021-04-21
description: replace a string's last 3 characters with the other string's last 3 characters
******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
	int len1, len2;
	int i, j;
	char s1[100], s2[100];
	printf("input s1(<100):");
	gets(s1);
	printf("input s2(<100):");
	gets(s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	
	
	if(len1<=len2)
	{
		if (len1<3)
		{
			for(i=len1-1,j=len2-1;i>=0;i--,j--)
			{
				s2[j] = s1[i];
			}
		}
		else
		{
			for(i=len1-1,j=len2-1;i>=len1-3;i--,j--)
			{
				s2[j] = s1[i];
			}	
		}	
	}
	else
	{
		if(len2<3)
		{
			for(i=len1-1,j=len2-1;j>=0;i--,j--)
			{
				s2[j] = s1[i];
			}
		}
		else 
		{
			for(i=len1-1,j=len2-1;j>=len2-3;i--,j--)
			{
				s2[j] = s1[i];
			}
		}
	} 
	
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	
	return 0;
}
