#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdlib.h>
#include <stdio.h>

typedef struct queue {
	char data;
	struct queue* link;
}Queue;

void push(Queue** front, Queue** rear, char c) {
	Queue* novi = NULL;
	novi = (Queue*)malloc(sizeof(Queue));
	if (!novi) {
		printf("Queue overflow.\n");
		exit(1);
	}
	novi->data = c;
	novi->link = NULL;
	if (*rear == NULL) {
		*front = novi;
		*rear = *front;
	}
	else {
		(*rear)->link = novi;
		*rear = novi;
	}
}

char pop(Queue** front, Queue** rear) {
	if ((*front == *rear) && (*rear == NULL)) {
		printf("There is no elements in Queue.\n");
		exit(1);
	}
	Queue* old = *front;
	char val = old->data;
	*front = (*front)->link;
	if (*front == NULL)
		*rear = (*rear)->link;
	free(old);

	return val;
}

// A binary tree Node
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef struct ListNode {
	int data;
	struct ListNode* next;
}ListNode;

ListNode* addNode(ListNode* head, int data) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = data;
	temp->next = head;
	return temp;
}

void preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

TreeNode* createTreeNode(int data) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = node->right = NULL;
	node->data = data;

	return node;
}

// Function to convert LinkedList to Binary tree
TreeNode* convertListToBinaryTree(ListNode* head) {
	// Base Case: empty list 
	if (!head) {
		return NULL;
	}

	TreeNode* root = createTreeNode(head->data);

	// move head pointer to next pointer
	head = head->next;


}