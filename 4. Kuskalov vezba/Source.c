#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct edge {
	int i;
	int j;
	int w;
}edge;

typedef struct edge_list {
	edge data[MAX];
	int n;
}edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void sort() {
	for(int i = 1; i < elist.n; i++)
		for(int j = 0; j < elist.n - 1; j++) 
			if (elist.data[j].w > elist.data[j + 1].w) {
				edge temp = elist.data[j];
				elist.data[j] = elist.data[j + 1];
				elist.data[j + 1] = temp;
			}
}

void KruskalAlgorithm() {
	elist.n = 0;

	for(int i = 1; i < n; i++) 
		for (int j = 0; j < i; j++) 
			if (Graph[i][j] != 0) {
				elist.data[elist.n].i = i;
				elist.data[elist.n].j = j;
				elist.data[elist.n].w = Graph[i][j];
				elist.n = elist.n + 1;
			}

	sort();
	

}
int bsort(int n, int a[]) {
	int i, j, k, l;
	l = 1; 
	for (i = n - 1; l && (i > 0); i--)
		for (j = l = 0; j < i; j++)
			if (a[j] > a[j + 1]){
				k = a[j];
				a[j] = a[j + 1]; 
				a[j + 1] = k;
				l = 1;
			} 
}