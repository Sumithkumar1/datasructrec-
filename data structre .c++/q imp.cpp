// CPP program to find smallest multiple of a
// given number made of digits 0 and 9 only
#include <bits/stdc++.h>
using namespace std;

// Maximum number of numbers made of 0 and 9
#define MAX_COUNT 10000


vector<string> vec;

void generateNumbersUtil()
{
	// Create an empty queue of strings
	queue<string> q;
		
	// enqueue the first number
	q.push("9");
	

	for (int count = MAX_COUNT; count > 0; count--)
	{
		string s1 = q.front();
		q.pop();
		
		// storing the front of queue in the vector
		vec.push_back(s1);
		
		string s2 = s1;
		
		// Append "0" to s1 and enqueue it
		q.push(s1.append("0"));
		
		// Append "9" to s2 and enqueue it. Note that
		// s2 contains the previous front
		q.push(s2.append("9"));
	}
}


string findSmallestMultiple(int n)
{

	for (int i = 0; i < vec.size(); i++)

		// stoi() is used for string to int conversion
		if (stoi(vec[i])%n == 0)
			return vec[i];	
}


int main()
{
	generateNumbersUtil();
	int n = 7;
	cout << findSmallestMultiple(n);
	return 0;
}

