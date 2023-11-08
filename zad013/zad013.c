/* 11. Napisati C program koji vraća broj ponavljanja zadate vrednosti u listi. */

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

int brojPonavljanja(Elem* head, int broj) {
	int n = 0;
	while (head) {
		if (broj == head->broj) {
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
	head = dodajUListu(head, 10);
	head = dodajUListu(head, 13);
	head = dodajUListu(head, 3);
	head = dodajUListu(head, 10);
	head = dodajUListu(head, 4);
	head = dodajUListu(head, 10);
	head = dodajUListu(head, 10);

	printf("Broj ponavljanja:%d", brojPonavljanja(head, 10));
	return 0;
}