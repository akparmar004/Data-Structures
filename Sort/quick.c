#include<stdio.h>


void swap(int *arr,int a,int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void sortHelper(int *arr,int s, int e)
{
	if(s >= e)
	{
		return;
	}
	int pivot = s;
	int left = s+1;
	int right = e;
	
	while(left <= right)
	{
		if(arr[pivot] < arr[left] && arr[pivot] > arr[right])
		{
			swap(arr,left,right);
		}
		if(arr[left] <= arr[pivot])
		{
			left++;
		}
		if(arr[pivot] <= arr[right])
		{
			right--;
		}
	}
	swap(arr,pivot,right);
	
	int leftSubArrSmall = (right-1 - s) < (e - right+1);
		
	if(leftSubArrSmall)
	{
		sortHelper(arr,s,right-1);
		sortHelper(arr,right+1,e);
	}
	else
	{
		sortHelper(arr,right+1,e);
		sortHelper(arr,s,right-1);
	}
}

void sort(int *arr,int n)
{
	sortHelper(arr,0,n-1);
	return;
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
	int arr[] = {7,6,5,4,3,2,1},n;
	n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,n);
	print(arr,n);
}
