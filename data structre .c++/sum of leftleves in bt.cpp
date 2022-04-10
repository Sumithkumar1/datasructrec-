// A C++ program to find sum of all left leaves
#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node has key, pointer to left and right
children */
struct Node
{
	int key;
	struct Node* left, *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointer. */
Node *newNode(char k)
{
	Node *node = new Node;
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

/* Pass in a sum variable as an accumulator */
void leftLeavesSumRec(Node *root, bool isleft, int *sum)
{
	if (!root) return;

	// Check whether this node is a leaf node and is left.
	if (!root->left && !root->right && isleft)
		*sum += root->key;

	// Pass 1 for left and 0 for right
	leftLeavesSumRec(root->left, 1, sum);
	leftLeavesSumRec(root->right, 0, sum);
}

// A wrapper over above recursive function
int leftLeavesSum(Node *root)
{
	int sum = 0; //Initialize result

	// use the above recursive function to evaluate sum
	leftLeavesSumRec(root, 0, &sum);

	return sum;
}

/* Driver program to test above functions*/
int main()
{
	// Let us construct the Binary Tree shown in the
	// above figure
	int sum = 0;
	struct Node *root		 = newNode(20);
	root->left			 = newNode(9);
	root->right			 = newNode(49);
	root->right->left		 = newNode(23);
	root->right->right	 = newNode(52);
	root->right->right->left = newNode(50);
	root->left->left		 = newNode(5);
	root->left->right		 = newNode(12);
	root->left->right->right = newNode(12);

	cout << "Sum of left leaves is "
	<< leftLeavesSum(root) << endl;
	return 0;
}

