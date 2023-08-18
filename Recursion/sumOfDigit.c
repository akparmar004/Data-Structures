#include<stdio.h>

int sumOfDigit(int);

void main()
{
	int num,ans;
	printf("enter number to get sum of its digits : ");
	scanf("%d",&num);
	
	ans = sumOfDigit(num);
	printf("sum of all digit of %d is : %d",num,ans);
}

int  sumOfDigit(int n)
{
	if(n == 0)
	{
		return 0;
	}
		
	return (n%10) + sumOfDigit(n/10);
}
