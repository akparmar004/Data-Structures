#include<stdio.h>
int factorial(int);

void main()
{
	int ans,n;
	printf("enter number for get a factorial of it : ");
	scanf("%d",&n);
	ans = factorial(n);
	
	printf("factorial of %d is : %d\n",n,ans);	
}

int factorial(int n)
{
	if(n == 1)
	{
		return n;
	}
	
	return n * factorial(n-1);
}
