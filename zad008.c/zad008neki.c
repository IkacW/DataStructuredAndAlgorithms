/*
U datoteci zad4.in u provm redu su dati brojevi n i m koji predstavljaju dužine dva ulazna niza. 
U narednih n + m redova su dati elementi ta dva niza. Učitati nizove iz datoteke i napisati program koji
objedinjuje ta dva niza u treći, dužine n+m. Ulazni nizovi su sortirani u rastućem poretku. Neophodno je
da i novoformirani niz bude sortiran u rastućem poretku. Zabranjeno je sortirati niz nakon formiranja. Rezultujući
niz upisati u datoteku zad4.out i to tako što ćete u prvom redu zapisati dužinu niza, a u ostalim redovima članove niza.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
void ucitajURastucem(int niz[], int trenDuz, int value) {
	int i = trenDuz - 1;
	while (niz[i] > value && i >= 0) {
		niz[i + 1] = niz[i];
		i--;
	}
	niz[i + 1] = value;
}

void ucitajMatricu(int niz[], int n, FILE* f) {
	int trenDuz = 0, value;
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d", &value);
		ucitajURastucem(niz, trenDuz, value);
		trenDuz++;
	}
}

void ispisiMatricu(int niz[], int n) {
	printf("Ispis niza:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n\n");
}

void spojiMatrice(int niz[], int niz1[], int niz2[], int n, int m, int* p) {
	for (int i = 0; i < n; i++) {
		niz[i] = niz1[i];
	}

	*p = n;

	for (int i = 0; i < m; i++) {
		ucitajURastucem(niz, *p, niz2[i]);
		(*p)++;
	}
}

int main() {
	int niz[20], niz1[10], niz2[10], trenDuz, value, n, m, p;
	FILE* f = fopen("zad008.txt", "r");

	fscanf(f, "%d %d", &n, &m);

	ucitajMatricu(niz1, n, f);
	ucitajMatricu(niz2, m, f);
	
	fclose(f);

	spojiMatrice(niz, niz1, niz2, n, m, &p);

	ispisiMatricu(niz1, n);
	ispisiMatricu(niz2, m);
	ispisiMatricu(niz, p);

	return 0;
}