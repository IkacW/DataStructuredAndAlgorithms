/*
Napisati C program koji pronalazi najveću dužinu povezanih elemenata matrice koje sadrže 1 u 0-1 matrici.
Data je matrica koja za elemente ima 0 ili 1. Kaže se da su dva elementa povezana ako su jedan do drugog horizontalno,
vertikalno ili dijagonalno. U jednoj matrici može biti više povezanih regiona. 
Ulaz: 
	1 1 0 0 0		 Izlaz: 5
	0 1 1 0 0
	0 0 1 0 1
	1 0 0 0 1
	0 1 0 1 1
Ideja: Za svaki element pretraži svih 8 pravaca i nastaviti pretragu u pravcima gde se povećava broj 1-ca.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdio.h>

// kada se pristupa uglastim garadama dinamickom nizu ili matrici, onda nam se automatski dereferencira
// cita se kao *(*(mat+i)+j)
void ucitaj(int** mat, int n, int m, FILE* f) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(f, "%d ", (*(mat + i) + j));
		}
	}
}

void ispisi(int** mat, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d  ", *(*(mat + i) + j));
		}
		printf("\n");
	}
}

void ispitajDijagonalu(int** mat, int n, int m, int* max) {
	int i = 0;
	for (int j = 0; j < m; j++) {
		i = 0;
		printf("\nmat(%d,%d)\n", i, j);
		int c = j;
		while (i < n && c < m) {
			if (mat[i][c] == 1) {
				int p = i, k = c, novamax = 0;
				while (mat[p][k] == 1 && p < n && k < m) {
					novamax++;
					printf("(%d,%d) : ", p, k);
					if (p == m - 1 && k == n - 1 )
						break;
					p++; k++;
				}
				if (novamax > *max) {
					*max = novamax;
				}
				novamax = 0;
			}
			i++; c++;
		}
	}
}

void ispitajHorizontalu(int** mat, int n, int m, int* max) {
	int novimax = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1) {
				while (mat[i][j] == 1 ) {
					novimax++;
					j++;
				}
				if (novimax > *max) {
					*max = novimax;
				}
			}
			novimax = 0;
		}
		novimax = 0;
	}
}

void ispitajVertikalu(int** mat, int n, int m, int* max) {
	int novimax;
	for (int j = 0; j < m; j++) {
		novimax = 0;
		for (int i = 0; i < n; i++) {
			if (mat[i][j] == 1) {
				while (mat[i][j] == 1) {
					novimax++;
					if (i == n - 1 && mat[i][j] == 1)
						break;
					i++;
				}
				if (novimax > *max) {
					*max = novimax;
				}
			}
			novimax = 0;
		}
		novimax = 0;
	}
}

int ispitaj(int** mat, int n, int m) {
	int max = 0;
	//ispitajHorizontalu(mat, n, m, &max);
	//ispitajVertikalu(mat, n, m, &max);
	ispitajDijagonalu(mat, n, m, &max);
	return max;
}

int main() {
	int n, m;
	FILE* f = fopen("zad009.txt", "r");
	fscanf(f, "%d%d", &n, &m);
	int** mat = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat[i] = (int*)calloc(m, sizeof(int));
	}

	ucitaj(mat, n, m, f);
	fclose(f);
	ispisi(mat, n, m);
	printf("Broj: %d", ispitaj(mat, n, m));
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
	return 0;
}