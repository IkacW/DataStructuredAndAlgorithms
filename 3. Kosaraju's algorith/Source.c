#include<stdio.h>
#include<stdlib.h>

#define MAXVERTICES 20 
#define MAXEDGES 20

typedef enum {FALSE, TRUE, TRISTATE} bool;

typedef struct node node;

struct node {
	int dst;
	node *next;
};

void printGraf(node *graph[], int nvert) {
	int i; 
	for(i=0; i<nvert; ++i) { 
		node *ptr;
		for(ptr=graph[i]; ptr; ptr=ptr->next)
			printf( "[%d] ", ptr->dst );
		printf( "\n");
	}
}

void napraviIvicu(node **ptr, int dst) {
	node *newnode = (node *)malloc(sizeof(node));
	newnode->dst = dst;
	newnode->next = *ptr;
	*ptr = newnode;
}

void buildGraph(node *graph[], int edges[2][MAXEDGES], int nedges ) {
	for(int i = 0; i < nedges; ++i) {
		insertEdge(graph+edges[0][i], edges[1][i]);
		insertEdge(graph+edges[1][i], edges[0][i]);
	}
}


void dfs( int v, int* visited, node *graph[] ) {
	node *ptr;visited[v] = TRISTATE;
	printf( "%d \n", v );
	for( ptr=graph[v]; ptr; ptr=ptr->next )
		if( visited[ ptr->dst ] == FALSE )
			dfs(ptr->dst, visited, graph);
}

void printSetTristate(int* visited, int nvert) {
	int i; 
	for (i = 0; i < nvert; ++i)
		if (visited[i] == TRISTATE) {
			printf("%d ", i); 
			visited[i] = TRUE; 
		}
	
	printf("\n\n"); 
}

void compINC(node* graph[], int nvert) {
	int* visited; 
	int i; 
	visited = (int*)malloc(nvert * sizeof(int)); 
	for (i = 0; i < nvert; ++i)
		visited[i] = FALSE; 
	for (i = 0; i < nvert; ++i)
		if (visited[i] == FALSE) {
			dfs(i, visited, graph);
			printSetTristate( visited, nvert );
		}
}
