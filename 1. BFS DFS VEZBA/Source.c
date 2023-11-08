#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdlib.h>
#include <stdio.h>
#define MAX 10

typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct graph {
	int V;
	int* visited;
	Node** adjList;
}Graph;

Node* createNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;

	return node;
}

Graph* createGraph(int n) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->adjList = (Node**)calloc(n, sizeof(Node*));

	graph->V = n;

	graph->visited = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		graph->adjList[i] = NULL;
		graph->visited[0] = 0;
	}

	return graph;
}

Graph* addEdge(Graph* graph, int src, int dest) {
	Node* newNode = createNode(dest);
	newNode->next = graph->adjList[src];
	graph->adjList[src] = newNode;

	return graph;
}

Node* push(Node* node, int data) {
	if (!node) {
		node = createNode(data);
		return node;
	}

	Node* temp = node;

	while (temp->next)
		temp = temp->next;

	temp->next = createNode(data);
	return node;
}

Node* pop(Node* node) {
	if (!node)
		return NULL;
	 
	Node* temp = node->next;

	free(node);

	return temp;
}

int peek(Node* node) {
	if (!node)
		return INT_MIN;

	return node->data;
}

void printQueue(Node* head) {
	while (head) {
		printf("| %d |\n", head->data);
		head = head->next;
	}
}

void printGraph(Graph* graph, int n) {
	for (int v = 0; v < n; v++) {
		Node* temp = graph->adjList[v];
		printf("\n Adjacency list of vertex %d\n ", v);
		while (temp) {
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void bfs(Graph* graph, int startVertex) {
	Node* queue = NULL;

	queue = push(queue, startVertex);
	graph->visited[startVertex] = 1;

	while (queue) {
		int currentVertex = peek(queue);
		queue = pop(queue);
		printf("Visiting %d\n", currentVertex);

		Node* temp = NULL;
		temp = graph->adjList[currentVertex];

		while (temp) {
			if (graph->visited[temp->data] == 0) {
				queue = push(queue, temp->data);
				graph->visited[temp->data] = 1;
			}
			temp = temp->next;
		}
		printQueue(queue);
	}
}

void dfs(Graph* graph, int startingVertex) {
	printf("Visiting %d\n", startingVertex);
	Node* temp = graph->adjList[startingVertex];
	while (temp) {
		if (graph->visited[temp->data] == 0) {
			graph->visited[temp->data] = 1;
			dfs(graph, temp->data);
		}
		temp = temp->next;
	}
}

void resetVisited(Graph* graph) {
	for (int i = 0; i < graph->V; i++) {
		graph->visited[i] = 0;
	}
}

// topolosko sortiranje

int inDegree(Graph* graph, int x) {
	int n = graph->V;
	int count = 0;

	for (int i = 0; i < n; i++) {
		Node* temp = graph->adjList[i];
		while (temp) {
			if (temp->data == x) {
				count++;
			}
			temp = temp->next;
		}
	}

	return count;
}

void topological_sort(Graph* graph) {
	int n = graph->V;

	int arr[MAX];
	int flag[MAX];

	for (int i = 0; i < n; i++) {
		arr[i] = inDegree(graph, i);
		flag[i] = 0;
	}

	int count = 0;
	while (count < n) {
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0 && flag[i] == 0) {
				printf("%d ", i);
				flag[i] = 1;
				Node* temp = graph->adjList[i];
				while (temp) {
					int data = temp->data;
					arr[data]--;
					temp = temp->next;
				}
			}
		}
		count++;
	}
}

int main() {
	Graph* graph = NULL;
	graph = createGraph(4);
	graph = addEdge(graph, 0, 1);
	graph = addEdge(graph, 0, 2);
	graph = addEdge(graph, 2, 3);
	graph = addEdge(graph, 1, 3);

	//printGraph(graph, 13);
	
	//bfs(graph, 0);

	//resetVisited(graph);
	//printf("\n");

	//printf("%d\n", inDegree(graph, 0));
	//printf("%d\n", inDegree(graph,7));
	//printf("%d\n", inDegree(graph, 10));

	topological_sort(graph);

	//dfs(graph, 0);
	return 0;
}