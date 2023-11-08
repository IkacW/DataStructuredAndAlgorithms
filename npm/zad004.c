/*
* U provom redu ulazne datoteke se nalazi broj članova, a u svakom narednom po jedan član niza.
* Napisati funkciju int prosekParnih(int [] niz) koja računa i vraća prosek parnih elemenata niza 
* (onih koji imaju parne vrednosti, a ne na parnim mestima u nizu).
*/


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

float prosekParnihElemenata(int niz[], int n) {
	int suma = 0, brojac = 0;
	for (int i = 0; i < n; i++) {
		if (niz[i] % 2 == 0) {
			suma += niz[i];
			brojac++;
		}
	}

	return (float)suma / brojac;
}

int main() {
	int n, niz[100];
	FILE* f = fopen("zad004.txt", "r");

	fscanf(f, "%d", &n);
	
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d", &niz[i]);
	}
	fclose(f);

	printf("Prosek parnih elemanta: %f", prosekParnihElemenata(niz, n));

	return 0;
}