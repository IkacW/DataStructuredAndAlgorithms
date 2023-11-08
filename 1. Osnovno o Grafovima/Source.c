/*
Racunanje ulazonog i izlaznog stepena cvora grafa predstavljenog pomocu matrice susedstva
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdlib.h>
#include <stdio.h>
#define MAX 10

void createGraph(int graph[][MAX], int n) {
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			printf("Eneter 1 if there is an edge between %d and %d, otherwise enter 0: ", i, j);
			scanf("%d", &graph[i][j]);
			printf("\n");
		}
}

int calculateOutdegree(int graph[][MAX], int x, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += graph[x][i];
	return sum;
}		

int calculateIndegree(int graph[][MAX], int x, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += graph[i][x];
	return sum;
}

int main() {
	int graph[MAX][MAX], node, n, i;
	printf("Enter the number of nodes(max is %d):", MAX);
	scanf("%d", &n);

	createGraph(graph, n);

	for (int i = 0; i < n; i++) {
		printf("The Indegree of node %d is: %d\n", i, calculateIndegree(graph, i, n));
		printf("The Outdegree of node %d is: %d\n", i, calculateOutdegree(graph, i, n));
	}

	return 0;
}