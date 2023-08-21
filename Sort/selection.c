#include<stdio.h>

void swap(int *p,int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

void printArr(int *p,int n)
{
	for(int i = 0;i < n;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}

void sort(int arr[], int n)
{
	int i,j,min;
	for(i = 0;i < n-1;i++)
	{
		min = i;
		for(j = i+1;j < n;j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		
		if(min != i)
		{
			swap(&arr[min],&arr[i]);
		}
	}	
}

void main()
{
	int size,n;
	printf("enter size of an array : ");
	scanf("%d",&size);
	int arr[size];
	
	printf("enter elements of an array : ");
	for(int i = 0;i < size;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,n);
	printf("sorted arr : ");
	printArr(arr,n);
}
