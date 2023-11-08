#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

// Function to check if a given binary tree holds children-sum property
int hasChildrenSumProperty(Node* root) {
	// base case: empty root
	if (!root)
		return 0;

	// base case: leaf
	if ((root->left == NULL) && (root->right == NULL)) {
		return root->data;
	}

	int left = hasChildrenSumProperty(root->left);
	int right = hasChildrenSumProperty(root->right);

	if ((left != INT_MIN) && (right != INT_MIN) && (root->data == left + right)) {
		return root->data;
	}

	return INT_MIN;
}

Node* createNode(int data) {
	Node* root = (Node*)malloc(sizeof(Node));
	root->left = root->right = NULL;
	root->data = data;

	return root;
}


int main() {
	Node* root = NULL;
	root = createNode(25);
	root->left = createNode(12);
	root->right= createNode(13);
	root->left->left = createNode(7);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	if (hasChildrenSumProperty(root) != INT_MIN) {
		printf("Binary tree holds children-sum property.");
	}
	else {
		printf("Binary tree does not hold cildren-sum property.");
	}

	return 0;
}

