// C++ simple program to
// find elements which are
// not present in second array
#include<bits/stdc++.h>
using namespace std;

// Function for finding
// elements which are there
// in a[] but not in b[].
void findMissing(int a[], int b[],
				int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < m; j++)
			if (a[i] == b[j])
				break;

		if (j == m)
			cout << a[i] << " ";
	}
}

// Driver code
int main()
{
	int a[] = { 1, 2, 6, 3, 4, 5 };
	int b[] = { 2, 4, 3, 1, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	int m = sizeof(b) / sizeof(b[1]);
	findMissing(a, b, n, m);
	return 0;
}

