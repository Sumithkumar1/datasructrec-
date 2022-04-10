// C++ program to round the given
// integer to a whole number
#include <bits/stdc++.h>
using namespace std;

// function to round the number
int round(int n)
{
	// Smaller multiple
	int a = (n / 10) * 10;
	
	// Larger multiple
	int b = a + 10;

	// Return of closest of two
	return (n - a > b - n)? b : a;
}

// driver function
int main()
{
	int n = 4722;
	cout << round(n) << endl;
	return 0;
}

