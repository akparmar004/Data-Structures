#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rev(char *str)
{
	int length = strlen(str);
	char* revstr = malloc(sizeof(length+1));

	for(int i = length - 1, j = 0; i >= 0; i--, j++)
		revstr[j] = str[i];

	revstr[length] = '\0';

	strcpy(str, revstr);

	free(revstr);
}
void main()
{
	char string[] = "arjun";
	
	rev(string);
	printf("%s\n",string);
}
