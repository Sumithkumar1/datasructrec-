// C++ to find number of integer less or greater given
// integer queries
#include<bits/stdc++.h>
using namespace std;

// Return the index of integer which are not less than x
// (or greater than or equal to x)
int lower_bound(int arr[], int start, int end, int x)
{
	while (start < end)
	{
		int mid = (start + end)>>1;
		if (arr[mid] >= x)
			end = mid;
		else
			start = mid + 1;
	}

	return start;
}

// Return the index of integer which are greater than x.
int upper_bound(int arr[], int start, int end, int x)
{
	while (start < end)
	{
		int mid = (start + end)>>1;
		if (arr[mid] <= x)
			start = mid + 1;
		else
			end = mid;
	}

	return start;
}

void query(int arr[], int n, int type, int x)
{
	// Counting number of integer which are greater than x.
	if (type)
		cout << n - upper_bound(arr, 0, n, x) << endl;

	// Counting number of integer which are not less than x
	// (Or greater than or equal to x)
	else
		cout << n - lower_bound(arr, 0, n, x) << endl;
}

// Driven Program
int main()
{
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr)/sizeof(arr[0]);

	sort(arr, arr + n);

	query(arr, n, 0, 5);
	query(arr, n, 1, 3);
	query(arr, n, 0, 3);

	return 0;
}

