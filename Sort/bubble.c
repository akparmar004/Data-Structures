#include<stdio.h>

void swap(int *p,int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void sort(int arr[],int n)
{
	int i,j,swapped;
	
	for(i = 0;i < n-1;i++)
	{
		swapped = 0;
		for(j = 0;j < n-1-i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				swapped = 1;
			}
		}
		
		if(swapped == 0)
		{
			break;
		}
	}
}

void print(int *arr,int n)
{
	for(int i = 0;i < n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void main()
{
	int arr[] = {10,20,5,3,4,22,15,12},n;
	n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,n);
	printf("sorted array : ");
	print(arr,n);
}
