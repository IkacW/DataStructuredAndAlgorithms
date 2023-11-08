#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
	int u;
	int v;
	int w;
}edge;

typedef struct graph {
	int V;
	int E;
	edge* edge;
} Graph;

#define mV 10
#define INF 99999

void display(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bellmanFord(Graph* graph, int source) {
	int lenght[mV];
	int nest[mV];

	int tV = graph->V;
	int tE = graph->E;

	for (int i = 0; i < tV; i++) {
		lenght[i] = INF;
		nest[i] = 0;

	}

	lenght[source] = 0;

	int u, v, w;
	for (int i = 0; i < tV; i++) {
		for (int j = 0; j < tE; j++) {
			u = graph->edge[j].u;
			v = graph->edge[j].v;
			w = graph->edge[j].w;

			if (lenght[u] != INF && lenght[v] > lenght[u] + w) {
				lenght[v] = lenght[u] + w;
				nest[v] = u;
			}
		}
	}

	// PROVERA
	for (int i = 0; i < tE; i++) {
		u = graph->edge[i].u;
		v = graph->edge[i].v;
		w = graph->edge[i].w;

		if (lenght[u] != NULL && lenght[u] > lenght[u] + w) {
			printf("Negative weight circle detected!\n");
			return;
		}
	}

	printf("Shortest path form %d to every node is: ", source);
	display(lenght, tV);
	display(nest, tV);
}


int main() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = 4;
	graph->E = 5;

	graph->edge = (edge*)malloc(graph->E * sizeof(edge));

	graph->edge[0].u = 0;
	graph->edge[0].v = 1;
	graph->edge[0].w = 5;

	//edge 0 --> 2
	graph->edge[1].u = 0;
	graph->edge[1].v = 2;
	graph->edge[1].w = 4;

	//edge 1 --> 3
	graph->edge[2].u = 1;
	graph->edge[2].v = 3;
	graph->edge[2].w = -3;

	//edge 2 --> 1
	graph->edge[3].u = 2;
	graph->edge[3].v = 1;
	graph->edge[3].w = 6;

	//edge 3 --> 2
	graph->edge[4].u = 3;
	graph->edge[4].v = 2;
	graph->edge[4].w = 2;

	bellmanFord(graph, 0);

	return 0;
}