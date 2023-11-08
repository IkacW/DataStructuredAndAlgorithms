/*
Dati su brojevi d, m, n i jednostruko povezana lista celih brojeva. Naći broj podlisti date liste,
sastavljene od susednih elemenata početne liste koje su dužinem, a zbir elemenata podliste je jednak d.
U prva dva reda ulazne datoteke zad1.in se nalaze brojevi d i m, a u narednom redu  n,  dok  se  u  narednih n
redova  nalazi  n celih  brojeva  koji  predstavljaju elemente  liste. Rezultat zapisati u datoteku zad1.out.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdio.h>

typedef struct elem {
	int broj;
	struct elem* link;
}Elem;

Elem* upisi(FILE* f, int* d, int* m, int* n) {
	Elem* head = NULL;
	Elem* novi = NULL;
	Elem* posl = NULL;

	fscanf(f, "%d", d);
	fscanf(f, "%d", m);
	fscanf(f, "%d", n);

	for (int i = 0; i < *n; i++) {
		novi = (Elem*)malloc(sizeof(Elem));
		fscanf(f, "%d", &novi->broj);
		novi->link = NULL;
		
		if (!head) {
			head = novi;
			posl = novi;
		}
		else {
			posl->link = novi;
			posl = novi;
		}
	}
	return head;
}

void pisi(Elem* head) {
	while (head) {
		printf("| %d | ", head->broj);

		head = head->link;
	}
}

int brojPodlisti(Elem* head, int d, int m) {
	Elem* pom = NULL;
	int brojac = 0;

	while (head) {
		int zbir = 0;
		pom = head;
		for (int i = 0; i < m; i++) {
			if (pom == NULL) {
				zbir = d + 1;
				break;
			}
			zbir += pom->broj;

			pom = pom->link;
		}
		if (zbir == d) 
			brojac++;

		head = head->link;
	}

	return brojac;
}

int main() {
	Elem* head = NULL;
	int n, m, d;

	FILE* f = fopen("zad023.txt", "r");
	head = upisi(f, &d, &m, &n);
	fclose(f);

	pisi(head);
	printf("\n");

	printf("Broj podlisti:%d", brojPodlisti(head, d, m));

	return 0;
}