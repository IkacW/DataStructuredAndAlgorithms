/*Napisati C program koji će vratiti koliko elemenata liste ima vrednost veću od elementa na početku liste.*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
	int broj;
	struct elem* link;
}Elem;

Elem* dodajUListu(Elem* head, int broj) {
	Elem* novi = NULL;
	novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	novi->link = head;
	head = novi;

	return head;
}

int prebrojiVece(Elem* head) {
	if (!head) {
		printf("Nema elemenata u listi.");
		return 0;
	}
	int broj = head->broj;
	int n = 0;
	head = head->link;
	while (head) {
		if (head->broj > broj) {
			n++;
		}
		head = head->link;
	}
	return n;
}

int main() {
	Elem* head = NULL;

	head = dodajUListu(head, 1);
	head = dodajUListu(head, 10);
	head = dodajUListu(head, 7);
	head = dodajUListu(head, 2);
	head = dodajUListu(head, 6);
	head = dodajUListu(head, 13);
	head = dodajUListu(head, 3);

	printf("Broj elemenata vecih od prvog: %d\n", prebrojiVece(head));

	return 0;
}