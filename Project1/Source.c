#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdlib.h>
#include <stdio.h>
#define MAX 10


struct node{ int data; 
struct node* link; 
};
/* funkcija uz pomoc koje pravimo matricu susedstva */
void buildadjm(int adj[][MAX], int n) {
	int i, j; 
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) { 
			printf("Unesi 1 ako postoji veza izmedju %d i %d, inace unesi 0 \n", i, j); 
			scanf("%d", &adj[i][j]); 
		}
}
/* funkcija za racunanje izlaznog stepena cvora */
int outdegree( int adj[][MAX], int x, int n) { 
	int i, count = 0; 
	for (i = 0; i < n; i++)
		if (adj[x][i] == 1)
			count++;
	return(count);
}
/* funkcija za racunanje ulaznog stepena grafa */
int indegree(int adj[][MAX], int x, int n) {
	int i, count = 0;
	for (i = 0; i < n; i++)
		if (adj[i][x] == 1)
			count++;
	return(count); 
}
/* A function to insert a new node in queue*/
struct node* addqueue(struct node* p, int val) {
	struct node* temp;
	if (p == NULL) {
		p = (struct node*)malloc(sizeof(struct node));
		/* insert the new node first node*/
		if (p == NULL) {
			printf("Rezervisanje memorije nije uspelo\n");
			exit(0);
		}
		p->data = val;
		p->link = NULL;
	}
	else {
		temp = p;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = (struct node*)malloc(sizeof(struct node));
		temp = temp->link;
		if (temp == NULL) {
			printf("Rezervisanje memorije nije uspelo\n");
			exit(0);
		}
		temp->data = val;
		temp->link = NULL;
	}
	return(p);
}

struct node* deleteq(struct node* p, int* val) { 
	struct node* temp;
	if (p == NULL) {
		printf("red je prazan\n"); 
		return(NULL);
	} *val = p->data;
	temp = p;
	p = p->link;
	free(temp);
	return(p);
}
void bfs(int adj[][MAX], int x, int visited[], int n, struct node** p) {
	int y, j, k;
	*p = addqueue(*p, x);
	do {
		*p = deleteq(*p, &y); 
		if (visited[y] == 0) { 
			printf("\nObilazim cvor = %d\t", y);
			visited[y] = 1;
			for (j = 0; j < n; j++)
				if ((adj[y][j] == 1) && (visited[j] == 0))
					*p = addqueue(*p, j);
		}
	} while ((*p) != NULL);
}
void dfs(int x, int visited[], int adj[][MAX], int n) {
	int j;
	visited[x] = 1;
	printf("Posecen je cvor %d\n", x); 
	for (j = 0; j < n; j++)
		if (adj[x][j] == 1 && visited[j] == 0)
			dfs(j, visited, adj, n);
}

voidmain() {
	int adj[MAX][MAX], n, i, s;
	struct node* start = NULL; 
	int visited[MAX]; 
	printf("Unesi broj cvorova grafa, maximum = %d\n", MAX);
	scanf("%d", &n); 
	buildadjm(adj, n);
	for (i = 0; i < n; i++) {
		printf("Ulazni stepen cvora %d je %d\n", i, indegree(adj, i, n));
		printf("Izlazni stepen cvora %d je %d\n", i, outdegree(adj, i, n));
	}
	
	while (1) {
		printf("\n****************** BFS algoritam *****************\n");
		printf("Unesi startni cvor: ");
		scanf("%d", &s);
		if (s == 0) break;
		for (i = 0; i < n; i++)
			visited[i] = 0;
		bfs(adj, s, visited, n, &start);
	}

	printf("\n****************** DFS algoritam *****************\n");
	for (i = 0; i < n; i++)
		if (visited[i] == 0)
			dfs(i, visited, adj, n);
}