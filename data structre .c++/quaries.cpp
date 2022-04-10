// CPP program to perform range queries over range
// queries.
#include <bits/stdc++.h>
using namespace std;

// Function to execute type 1 query
void type1(int arr[], int start, int limit)
{
	
	for (int i = start; i <= limit; i++)	
		arr[i]++;
}

// Function to execute type 2 query
void type2(int arr[], int query[][3], int start, int limit)
{
	for (int i = start; i <= limit; i++) {

		if (query[i][0] == 1)
			type1(arr, query[i][1], query[i][2]);
		
		// If the query is of type 2 recursive call
		// to type 2 query
		else if (query[i][0] == 2)
			type2(arr, query, query[i][1], query[i][2]);	
	}
}


int main()
{

	int n = 5, m = 5;
	int arr[n + 1];
	for (int i = 1; i <= n; i++)
		arr[i] = 0;
	
	// Build query matrix
	int temp[15] = { 1, 1, 2, 1, 4, 5, 2,
					1, 2, 2, 1, 3, 2, 3, 4 };
	int query[5][3];
	int j = 0;
	for (int i = 1; i <= m; i++) {
		query[i][0] = temp[j++];
		query[i][1] = temp[j++];
		query[i][2] = temp[j++];
	}

	
	for (int i = 1; i <= m; i++)
		if (query[i][0] == 1)
			type1(arr, query[i][1], query[i][2]);
		else if (query[i][0] == 2)
			type2(arr, query, query[i][1], query[i][2]);	

	
	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
	
	return 0;
}

