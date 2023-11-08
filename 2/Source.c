#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

int size(Node* root) {
	return root ? 1 + size(root->left) + size(root->right) : 0;
}

// Returns true if the size of the given binary tree or any of its subtrees is exactly 'n/2'
bool checkSize(Node* root, int n) {
	if (!root)
		return false;
	
	if (size(root) * 2 == n)
		return true;

	return checkSize(root->left, n) || checkSize(root->right, n);
}

bool splitTree(Node* root) {
	int n = size(root);

	return (n % 2 == 0) && checkSize(root, n);
}

Node* createNode(int data) {
	Node* root = (Node*)malloc(sizeof(Node));
	root->right = root->left = NULL;
	root->data = data;
}

int main() {
	Node* root = NULL;
	root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->right = createNode(6);

	if (splitTree(root)) {
		printf("Tree can be split into two equal size trees.");
	}
	else {
		printf("Tree can not be splited into two equal size trees.");
	}

	while (1) {
		printf("nesto");
	}

	return 0;
}