/* Napisati program koji u jednostruko povezanoj linearnoj listi pronalazi i izbacuje element 
koji se nalazi nakon elementa sa najmanjom vrednošću */

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

Elem* dodajUListuKraj(Elem* head, FILE* f) {
	int n = 0;
	Elem* poslednji = head;

	while (!feof(f)) {
		Elem* novi = (Elem*)malloc(sizeof(Elem));
		fscanf(f, "%d ", &novi->broj);
		novi->link = NULL;

		if (head == NULL) {
			head = novi;
			poslednji = head;
		}
		
		poslednji->link = novi;
		poslednji = novi;
	}

	return head;
}

int najmanji(Elem* head) {
	int min = INT_MAX;
	if (head == NULL) {
		printf("Ne postoji niz! GRESKA!");
		exit(EXIT_FAILURE);
	}
	while (head) {
		if (head->broj < min) {
			min = head->broj;
		}
		head = head->link;
	}
	return min;
}

void pisi(Elem* head) {
	if (!head) {
		printf("Lista nema elemenata");
		return;
	}
	while (head) {
		printf("| %d |   ", head->broj);
		head = head->link;
	}
}

void izbaci(Elem* head) {
	if (!head) {
		exit(EXIT_FAILURE);
	}
	int min = najmanji(head);
	Elem* naredni = NULL;
	naredni = head->link;
	while (head) {
		if (head->broj == min && head->link != NULL) {
			naredni = head->link; //NULL
			head->link = head->link->link;
			if (naredni != NULL)
				free(naredni);
		}
		head = head->link;
	}
}

int main() {
	Elem* head = NULL;
	FILE* f;

	head = dodajUListu(head, 13);

	f = fopen("zad014.txt", "r");
	head = dodajUListuKraj(head, f);
	fclose(f);

	printf("Najmanji element:%d\n", najmanji(head));

	pisi(head);

	izbaci(head);

	printf("\n");
	pisi(head);

	return 0;
}