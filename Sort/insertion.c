#include<stdio.h>

void print(int *ptr,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",ptr[i]);
	}
	printf("\n");
}

void sort(int *arr,int n)
{
	int i,j,key;
	for(i = 1;i < n;i++)
	{
		key = arr[i];
		j = i - 1;
		
		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void main()
{
	int arr[] = {10,5,3,4,9},n;
	n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,n);
	print(arr,n);
}
