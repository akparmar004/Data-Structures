#include<stdio.h>

int gcd(int a,int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b,a % b);
}

void main()
{
	int a,b;
	printf("enter two numbers : ");
	scanf("%d %d",&a,&b);
	printf("%d\n",gcd(a,b));
}
