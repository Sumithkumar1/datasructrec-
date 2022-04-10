// C++ program to check whether X can give change
// to every person in the Queue
#include <bits/stdc++.h>
using namespace std;

// Function to check if every person will
// get the change from X
int isChangeable(int notes[], int n)
{
	// To count the 5$ and 10& notes
	int fiveCount = 0;
	int tenCount = 0;

	// Serve the customer in order
	for (int i = 0; i < n; i++) {

		// Increase the number of 5$ note by one
		if (notes[i] == 5)
			fiveCount++;
		else if (notes[i] == 10) {

			// decrease the number of note 5$ and
			// increase 10$ note by one
			if (fiveCount > 0) {
				fiveCount--;
				tenCount++;
			}
			else
				return 0;
		}
		else {

			// decrease 5$ and 10$ note by one
			if (fiveCount > 0 && tenCount > 0) {
				fiveCount--;
				tenCount--;
			}

			// decrease 5$ note by three
			else if (fiveCount >= 3) {
				fiveCount -= 3;
			}
			else
				return 0;
		}
	}

	return 1;
}
// Driver Code
int main()
{
	// queue of customers with available notes.
	int a[] = { 5, 5, 5, 10, 20 };
	int n = sizeof(a) / sizeof(a[0]);

	// Calling function
	if (isChangeable(a, n))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}

