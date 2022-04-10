// C++ program to implement unrolled linked list
// and traversing it.
#include <bits/stdc++.h>
using namespace std;
#define maxElements 4

// Unrolled Linked List Node
class Node
{
	public:
	int numElements;
	int array[maxElements];
	Node *next;
};

/* Function to traverse an unrolled linked list
and print all the elements*/
void printUnrolledList(Node *n)
{
	while (n != NULL)
	{
		// Print elements in current node
		for (int i=0; i<n->numElements; i++)
			cout<<n->array[i]<<" ";

		// Move to next node
		n = n->next;
	}
}

// Program to create an unrolled linked list
// with 3 Nodes
int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 Nodes
	head = new Node();
	second = new Node();
	third = new Node();

	// Let us put some values in second node (Number
	// of values must be less than or equal to
	// maxElement)
	head->numElements = 3;
	head->array[0] = 1;
	head->array[1] = 2;
	head->array[2] = 3;

	// Link first Node with the second Node
	head->next = second;

	// Let us put some values in second node (Number
	// of values must be less than or equal to
	// maxElement)
	second->numElements = 3;
	second->array[0] = 4;
	second->array[1] = 5;
	second->array[2] = 6;

	// Link second Node with the third Node
	second->next = third;

	// Let us put some values in third node (Number
	// of values must be less than or equal to
	// maxElement)
	third->numElements = 3;
	third->array[0] = 7;
	third->array[1] = 8;
	third->array[2] = 9;
	third->next = NULL;

	printUnrolledList(head);

	return 0;
}

// This is code is contributed by rathbhupendra

