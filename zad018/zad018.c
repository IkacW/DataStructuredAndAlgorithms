/* Napisati funkciju koja na osnovu zadate liste pravi drugu,sa elementima u obrnutom redosledu
u odnosu na prvu.Lista se zadaje u datoteci na standardni nacin. */

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

Elem* invertuj(Elem* head) {
	Elem* invertovana = NULL;
	
	while (head) {
		invertovana = naPocetak(invertovana, head->broj);
		head = head->link;
	}

	return invertovana;
}

int main() {
	Elem* head = NULL, * iHead = NULL;

	head = naPocetak(head, 10);
	head = naPocetak(head, 5);
	head = naPocetak(head, 2);
	head = naPocetak(head, 8);
	head = naPocetak(head, 7);
	head = naPocetak(head, 18);
	head = naPocetak(head, 13);
	head = naPocetak(head, 15);

	iHead = invertuj(head);

	pisi(head);
	printf("\n");
	pisi(iHead);

	return 0;
}