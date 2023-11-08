#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

typedef float tip;

tip** allocate(int n) {
	tip** mat;

	mat = (tip**)calloc(n, sizeof(tip*));
	for (int i = 0; i < n; i++) {
		mat[i] = (tip*)calloc(n, sizeof(tip));
	}

	return mat;
}

void deallocate(tip** mat, int n) {
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}

	free(mat);
}

void ispisiMatricu(tip** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2.f ", mat[i][j]);
		}
		printf("\n");
	}
}

void unesiMatricu(tip*** matrica, int* n) {
	printf("Unesi velicinu kvadratne matrice:\n");
	scanf("%d", n);
	*matrica = allocate(*n);

	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n; j++) {
			printf("A[%d][%d]=", i, j);
			scanf("%f", &(*matrica)[i][j]);
		}
	}
}

tip determinanta(tip** matrica, int n) {
	int i;
	tip** podmatrica;
	tip det = 0;
	int vrsta, kolona, znak;
	/* Izlaz iz rekurzije je matrica 1x1 */
	if (n == 1)
		return matrica[0][0];
	/* Podmatrica ce da sadrzi minore polazne matrice */
	podmatrica = allocate(n - 1);
	znak = 1;
	for (i = 0; i < n; i++) {
		for (kolona = 0; kolona < i; kolona++) {
			for (vrsta = 1; vrsta < n; vrsta++) {
				podmatrica[vrsta - 1][kolona] = matrica[vrsta][kolona];
			}
		}
		for (kolona = i + 1; kolona < n; kolona++) {
			for (vrsta = 1; vrsta < n; vrsta++) {
				podmatrica[vrsta - 1][kolona - 1] = matrica[vrsta][kolona];
			}
		}

		det += znak * matrica[0][i] * determinanta(podmatrica, n - 1);
		znak *= -1;
	}
	deallocate(podmatrica, n - 1);
	return det;
}

int main() {
	tip** matrica;
	int n;

	unesiMatricu(&matrica, &n);

	printf("Determinanta je:%2.f\n", determinanta(matrica, n));
	return 0;
}