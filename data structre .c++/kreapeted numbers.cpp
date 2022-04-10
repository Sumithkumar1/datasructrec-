// C++ implementation to find k numbers with most
// occurrences in the given array
//100 question inter beiw
#include <bits/stdc++.h>

using namespace std;

// comparison function to sort the 'freq_arr[]'
bool compare(pair<int, int> p1, pair<int, int> p2)
{
	// if frequencies of two elements are same
	// then the larger number should come first
	if (p1.second == p2.second)
		return p1.first > p2.first;


	return p1.second > p2.second;
}

// function to print the k numbers with most occurrences
void print_N_mostFrequentNumber(int arr[], int n, int k)
{
	// unordered_map 'um' implemented as frequency hash table
	unordered_map<int, int> um;
	for (int i = 0; i < n; i++)
		um[arr[i]]++;

	vector<pair<int, int> > freq_arr(um.begin(), um.end());


	sort(freq_arr.begin(), freq_arr.end(), compare);

	
	cout << k << " numbers with most occurrences are:\n";
	for (int i = 0; i < k; i++)
		cout << freq_arr[i].first << " ";
}


int main()
{
	int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	print_N_mostFrequentNumber(arr, n, k);
	return 0;
}

