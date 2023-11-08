/*
U binarno stablo smešta se niz podataka: 27, 52, 19, 17, 71, 23, 20, 5, 69 Treba nacrtati sortirano binarno stablo
(levi manji, desni veći) ako je stablo popunjavano redom kako su dolazili podaci.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = data;
	
	return tmp;
}

Node* sortedTree(Node* root, int data) {
	if (!root) {
		root = createNode(data);
		return root;
	}

	if (root->data > data) {
		root->left = sortedTree(root->left, data);
	}
	else if (root->data < data) {
		root->right = sortedTree(root->right, data);
	}
	else {
		if (rand() % 2 == 0) {
			root->left = sortedTree(root->left, data);
		}
		else {
			root->right = sortedTree(root->right, data);
		}
	}

	return root;
}

#define SPACE 5

void print2D(Node* stablo, int space) {
	if (!stablo)
		return;
	space += SPACE;
	print2D(stablo->right, space);
	printf("\n");
	for (int i = SPACE; i < space; i++)
		printf(" ");
	printf("%d", stablo->data);
	print2D(stablo->left, space);
}


// 27, 52, 19, 17, 71, 23, 20, 5, 69
int main() {
	Node* root = NULL;

	root = sortedTree(root, 27);
	root = sortedTree(root, 52);
	root = sortedTree(root, 19);
	root = sortedTree(root, 17);
	root = sortedTree(root, 71);
	root = sortedTree(root, 23);
	root = sortedTree(root, 20);
	root = sortedTree(root, 5);
	root = sortedTree(root, 69);

	print2D(root, 0);

	return 0;
}