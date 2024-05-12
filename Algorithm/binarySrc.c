#include<stdio.h>

int search(int arr[], int size, int ele)
{
	int s = 0, e = size - 1,mid;
	while(s <= e)
	{
		mid = s + (e - s)/2;	

		if(arr[mid] == ele)
			return mid;

		if(arr[mid] < ele)
			s = mid + 1;
		
		else
			e = mid - 1;
	}

	return -1;
}

void main()
{
	int arr[] = {11,15,16,19,23,29,33,56,100,105,111};
	int pos = search(arr, sizeof(arr)/sizeof(arr[0]),111);

	pos == -1? printf("element not found!!\n") : printf("element present at position : %d\n",pos);
}
