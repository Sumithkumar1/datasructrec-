// C++ program to implement a stack using
// Priority queue(min heap)
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

// User defined stack class
class Stack{
	
	int cnt;
	priority_queue<pair<int, int> > pq;
public:
	Stack():cnt(0){}
	void push(int n);
	void pop();
	int top();
	bool isEmpty();
};

// push function increases cnt by 1 and
// inserts this cnt with the original value.
void Stack::push(int n){
	cnt++;
	pq.push(pi(cnt, n));
}

// pops element and reduces count.
void Stack::pop(){
	if(pq.empty()){ cout<<"Nothing to pop!!!";}
	cnt--;
	pq.pop();
}


int Stack::top(){
	pi temp=pq.top();
	return temp.second;
}

// return true if stack is empty
bool Stack::isEmpty(){
	return pq.empty();
}

// Driver code
int main()
{
	Stack* s=new Stack();
	s->push(1);
	s->push(2);
	s->push(3);
	while(!s->isEmpty()){
		cout<<s->top()<<endl;
		s->pop();
	}
}

