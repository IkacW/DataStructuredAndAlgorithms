#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct egde {
	int i;
	int j;
	int w;
}Edge;

typedef struct edge_list {
	Edge data[MAX];
	int n;
}edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void sort() {

	for (int i = 1; i < elist.n; i++)
		for(int  j = 0; j < elist.n - 1; j++)
			if (elist.data[j].w > elist.data[j + 1].w) {
				Edge temp = elist.data[j];
				elist.data[j] = elist.data[j + 1];
				elist.data[j + 1] = temp;
			}
}

int find(int belongs[], int vertexno) {
	return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {
	for (int i = 0; i < n; i++) {
		if (belongs[i] == c2)
			belongs[i] = c1;
	}
}

void printSort() {
	int i, cost = 0;

	for (i = 0; i < elist.n; i++) {
		printf("\n%d - %d : %d", elist.data[i].i, elist.data[i].j, elist.data[i].w);
	}
}

void KruskalAlgorithm() {
	elist.n = 0;

	for(int i = 1; i < n; i++) 
		for(int j = 0; j < i; j++) 
			if (Graph[i][j] != 0) {
				printf("Pravim edge izmedju %d %d\n", i, j);
				elist.data[elist.n].i = i;
				elist.data[elist.n].j = j;
				elist.data[elist.n].w = Graph[i][j];
				elist.n = elist.n + 1;
			}

	sort();
	printSort();
	printf("\n");

	int belongs[MAX];
	for (int i = 0; i < n; i++)
		belongs[i] = i;

	int cno1;
	int cno2;

	spanlist.n = 0;

	for (int i = 0; i < elist.n; i++) {
		cno1 = find(belongs, elist.data[i].i);
		cno2 = find(belongs, elist.data[i].j);

		if (cno1 != cno2) {
			spanlist.data[spanlist.n] = elist.data[i];
			spanlist.n = spanlist.n + 1;
			applyUnion(belongs, cno1, cno2);
		}
	}
}

void printAlgo() {
	int i, cost = 0;

	for (i = 0; i < spanlist.n; i++) {
		printf("\n%d - %d : %d", spanlist.data[i].i, spanlist.data[i].j, spanlist.data[i].w);
		cost = cost + spanlist.data[i].w;
	}

	printf("\nSpanning tree cost: %d", cost);
}

int main() {
	Graph[0][0] = 0;
	Graph[0][1] = 4;
	Graph[0][2] = 4;
	Graph[0][3] = 0;
	Graph[0][4] = 0;
	Graph[0][5] = 0;
	Graph[0][6] = 0;

	Graph[1][0] = 4;
	Graph[1][1] = 0;
	Graph[1][2] = 2;
	Graph[1][3] = 0;
	Graph[1][4] = 0;
	Graph[1][5] = 0;
	Graph[1][6] = 0;

	Graph[2][0] = 4;
	Graph[2][1] = 2;
	Graph[2][2] = 0;
	Graph[2][3] = 3;
	Graph[2][4] = 4;
	Graph[2][5] = 0;
	Graph[2][6] = 0;

	Graph[3][0] = 0;
	Graph[3][1] = 0;
	Graph[3][2] = 3;
	Graph[3][3] = 0;
	Graph[3][4] = 3;
	Graph[3][5] = 0;
	Graph[3][6] = 0;

	Graph[4][0] = 0;
	Graph[4][1] = 0;
	Graph[4][2] = 4;
	Graph[4][3] = 3;
	Graph[4][4] = 0;
	Graph[4][5] = 0;
	Graph[4][6] = 0;

	Graph[5][0] = 0;
	Graph[5][1] = 0;
	Graph[5][2] = 2;
	Graph[5][3] = 0;
	Graph[5][4] = 3;
	Graph[5][5] = 0;
	Graph[5][6] = 0;

	n = 7;
	KruskalAlgorithm();
	printAlgo();

	return 0;
}