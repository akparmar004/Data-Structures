#include<stdio.h>
#include<string.h>
void sort(int *arr,int n);

void main()
{
	int arr[] = {9,2,1,5,60,5,3},i;
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	
	sort(arr,arrSize);
	
	for(i=0;i < arrSize;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void sort(int *ptr,int n)
{
	int output[n],i,max;
	max = ptr[0];
	
	for(i=1;i<n;i++)
	{
		if(ptr[i] > max)
		{
			max = ptr[i];
		}
	}
	
	int count[max+1];
	memset(count,0,sizeof(count));
	
	for(i=0;i<n;i++)
		++count[ptr[i]];
	
	for(i=1;i<=max;i++)
		count[i] = count[i] + count[i-1];
		
	for(i=0;i<n;i++)
	{
		output[count[ptr[i]] - 1] = ptr[i];
		--count[ptr[i]];
 	}
 	for(i=0;i<n;i++)
 	{
 		ptr[i] = output[i];
 	}
}
