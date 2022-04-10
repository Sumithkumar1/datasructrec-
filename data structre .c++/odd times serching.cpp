// C program to find the element that appears odd number of time
#include<stdio.h>

// A Binary Search based function to find the element
// that appears odd times
void search(int *arr, int low, int high)
{
	// Base cases
	if (low > high)
	return;
	if (low==high)
	{
		printf("The required element is %d ", arr[low]);
		return;
	}

	// Find the middle point
	int mid = (low+high)/2;


	if (mid%2 == 0)
	{
		if (arr[mid] == arr[mid+1])
			search(arr, mid+2, high);
		else
			search(arr, low, mid);
	}
	else // If mid is odd
	{
		if (arr[mid] == arr[mid-1])
			search(arr, mid+1, high);
		else
			search(arr, low, mid-1);
	}
}


int main()
{
	int arr[] = {1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40};
	int len = sizeof(arr)/sizeof(arr[0]);
	search(arr, 0, len-1);
	return 0;
}

