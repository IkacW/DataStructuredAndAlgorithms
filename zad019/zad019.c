/* Napisati metodu koja pravi istovetnu kopiju date liste.Lista je zadata standardno u datoteci. */

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>	
#include <stdlib.h>

typedef struct elem {
	int broj;
	struct elem* link;
}Elem;

Elem* naPocetak(Elem* head, int broj) {
	Elem* novi = NULL;
	novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	novi->link = head;
}

void pisi(Elem* head) {
	while (head) {
		printf("|   %d   |  ", head->broj);
		head = head->link;
	}
}

Elem* ucitaj(FILE* f) {
	Elem* head = NULL;
	Elem* poslednji = NULL;
	Elem* nova = NULL;

	while (!feof(f)) {
		nova = (Elem*)malloc(sizeof(Elem));
		fscanf(f, "%d", &nova->broj);
		nova->link = NULL;

		if (!head) {
			head = nova;
			poslednji = head;
		}
		else {
			poslednji->link = nova;
			poslednji = poslednji->link;
		}

	}
	return head;
}

Elem* kopiraj(Elem* head) {
	Elem* kopija = NULL;
	Elem* novi = NULL;
	Elem* poslednji = NULL;

	while (head) {
		novi = (Elem*)malloc(sizeof(Elem));
		novi->broj = head->broj;
		novi->link = NULL;

		if (kopija == NULL) {
			kopija = novi;
			poslednji = kopija;
			
		}
		else {
			poslednji->link = novi;
			poslednji = novi;
		}

		head = head->link;
	}
	return kopija;
}

int main() {
	Elem* head = NULL;
	Elem* kop = NULL;
	FILE* f = fopen("zad019.txt", "r");
	head = ucitaj(f);
	fclose(f);

	pisi(head);
	printf("\n");
	kop = kopiraj(head);
	pisi(kop);


	return 0;	
}