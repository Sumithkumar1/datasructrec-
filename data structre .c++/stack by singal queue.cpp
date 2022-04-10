// C++ program to implement a stack using
// single queue
#include<bits/stdc++.h>
using namespace std;

class Stack
{
	queue<int>q;
public:
	void push(int val);
	void pop();
	int top();
	bool empty();
};

// Push operation
void Stack::push(int val)
{
	// Get previous size of queue
	int s = q.size();

	// Push current element
	q.push(val);

	for (int i=0; i<s; i++)
	{
	
		q.push(q.front());

		// this will delete front element
		q.pop();
	}
}

// Removes the top element
void Stack::pop()
{
	if (q.empty())
		cout << "No elements\n";
	else
		q.pop();
}

// Returns top of stack
int Stack::top()
{
	return (q.empty())? -1 : q.front();
}

// Returns true if Stack is empty else false
bool Stack::empty()
{
	return (q.empty());
}

// Driver code
int main()
{
	Stack s;
	s.push(15);
	s.push(80);
	cout << s.top() << endl;
	s.pop();
	s.push(30);
	s.pop();
	cout << s.top() << endl;
	return 0;
}

