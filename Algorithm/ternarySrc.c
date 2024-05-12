#include<stdio.h>

int search(int s, int e, int ele, int arr[])
{
	int mid1, mid2;
	while(e >= s)
	{
		mid1 = s + (e-s)/3;
		mid2 = e - (e-s)/3;

		if(arr[mid1] == ele)
			return mid1;
		if(arr[mid2] == ele)
			return mid2;

		if(ele < arr[mid1])
			e = mid1-1;
		else if(ele > arr[mid2])
			s = mid2+1;
		else
			s = mid1+1, e = mid2-1;
	}

	return -1;
}

void main()
{
	int arr[] = {10,20,30,40,50,60,600,700,800,900,1000};
	int size = sizeof(arr)/sizeof(arr[0]);
	int pos = search(0,size-1,60,arr);

	pos == -1? printf("element not found!!\n") : printf("element found at index : %d\n", pos);
}
