#include<stdio.h>

int search(int arr[], int size, int ele)
{
	for(int i = 0;i < size;i++)
	{
		if(arr[i] == ele)
			return i;
	}
}


void main()
{
	int arr[] = {10,20,30,40,50};
	int size = sizeof(arr) / sizeof(arr[0]);

	int pos = search(arr,size,50);

	printf("element present at position : %d\n",pos);
}
