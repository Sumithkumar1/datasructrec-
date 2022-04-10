// C++ program to count all possible way to construct buildings
#include<iostream>
using namespace std;

// Returns count of possible ways for N sections
int countWays(int N)
{
	// Base case
	if (N == 1)
		return 4;
	int countB=1, countS=1, prev_countB, prev_countS;

	
	for (int i=2; i<=N; i++)
	{
		prev_countB = countB;
		prev_countS = countS;

		countS = prev_countB + prev_countS;
		countB = prev_countS;
	}


	int result = countS + countB;

	// Result for 2 sides is square of result for one side
	return (result*result);
}


int main()
{
	int N = 7;
	cout << "Count of ways for " << N
		<< " sections is " << countWays(N);
	return 0;
}

