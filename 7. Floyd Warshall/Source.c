#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

#define nV 4

#define INF 999

void printMatrix(int matrix[][nV]) {
	for (int i = 0; i < nV; i++) {
		for (int j = 0; j < nV; j++) {
			if (matrix[i][j] == INF) {
				printf("%s", "INF");
			}
			else {
				printf("%d ", matrix[i][j]);
			}
		}
		printf("\n");
	}
}

void floydWarshall(int graph[][nV]) {
	int matrix[nV][nV];

	for (int i = 0; i < nV; i++)
		for (int j = 0; j < nV; j++)
			matrix[i][j] = graph[i][j];

	for (int k = 0; k < nV; k++) {
		for (int i = 0; i < nV; i++) {
			for (int j = 0; j < nV; j++) {
				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}
	printMatrix(matrix);
}

int main() {
	int graph[nV][nV] = {
		{0, 3, INF, 5},
		{2, 0, INF, 4},
		{INF, 1, 0, INF},
		{INF, INF, 2, 0}
	};

	floydWarshall(graph);
}