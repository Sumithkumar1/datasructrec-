// C++ program to merge two max heaps.
//100 codes interwiew
#include <bits/stdc++.h>
using namespace std;


void maxHeapify(int arr[], int n, int idx)
{
	// Find largest of node and its children
	if (idx >= n)
		return;
	int l = 2 * idx + 1;
	int r = 2 * idx + 2;
	int max;
	if (l < n && arr[l] > arr[idx])
		max = l;
	else
		max = idx;
	if (r < n && arr[r] > arr[max])
		max = r;

	if (max != idx) {
		swap(arr[max], arr[idx]);
		maxHeapify(arr, n, max);
	}
}

// Builds a max heap of given arr[0..n-1]
void buildMaxHeap(int arr[], int n)
{
	
	for (int i = n / 2 - 1; i >= 0; i--)
		maxHeapify(arr, n, i);
}

// Merges max heaps a[] and b[] into merged[]
void mergeHeaps(int merged[], int a[], int b[],
				int n, int m)
{
	// Copy elements of a[] and b[] one by one
	// to merged[]
	for (int i = 0; i < n; i++)
		merged[i] = a[i];
	for (int i = 0; i < m; i++)
		merged[n + i] = b[i];

	
	buildMaxHeap(merged, n + m);
}

// Driver code
int main()
{
	int a[] = { 10, 5, 6, 2 };
	int b[] = { 12, 7, 9 };

	int n = sizeof(a) / sizeof(a[0]);
	int m = sizeof(b) / sizeof(b[0]);

	int merged[m + n];
	mergeHeaps(merged, a, b, n, m);

	for (int i = 0; i < n + m; i++)
		cout << merged[i] << " ";

	return 0;
}

