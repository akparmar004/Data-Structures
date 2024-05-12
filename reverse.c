#include<stdio.h>

int reverse(int x){
    long int temp = x;
    long int ans = 0;
    if(x > 0)
    {
        while(temp > 0)
        {
            ans = (ans*10) + (temp%10);
            temp /= 10;
        }
    }
    else
    {
        temp = (-1*temp);
        while(temp > 0)
        {
            ans = (ans*10) + (temp%10);
            temp /= 10;   
        }
        ans = (-1*ans);
    }
    return ans;
}

void main()
{
	long int i = 1534236469;
	printf("%d\n",reverse(i));
}
