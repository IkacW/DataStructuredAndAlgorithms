/* Napisati  funkciju  koja  iz  zadane  liste  u  koju  se  zapisuju  celi  brojevi  (int) briše parneelemente */

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
	Elem* novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	novi->link = head;
	head = novi;

	return head;
}

void pisi(Elem* head) {
	while (head) {
		printf("|   %d   |  ", head->broj);
		head = head->link;
	}
}

Elem* brisiParne(Elem* head) {
	Elem* pret = NULL, * tren = head;

	while (tren) {
		if (tren->broj % 2 == 0) {
			if (!pret) {
				head = head->link;
				free(tren);
				tren = head;
			}
			else {
				pret->link = tren->link;
				free(tren);
				tren = pret->link;
			}
		}
		else {
			pret = tren;
			tren = tren->link;
		}
	}
	return head;
}

int main() {
	Elem* head = NULL;

	head = naPocetak(head, 10);
	head = naPocetak(head, 5);
	head = naPocetak(head, 2);
	head = naPocetak(head, 8);
	head = naPocetak(head, 7);
	head = naPocetak(head, 18);
	head = naPocetak(head, 13);
	head = naPocetak(head, 15);

	pisi(head);
	printf("\n");
	head = brisiParne(head);

	pisi(head);

	return 0;
}