/*
Napisati program koji od date dve jednostruko spregnute listepravi treću
koja predstavlja uniju elemenata date dve liste. 
*/

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
	head = novi;

	return head;
}

void pisi(Elem* head) {
	while (head) {
		printf("|   %d   |  ", head->broj);
		head = head->link;
	}
}

Elem* naKraju(Elem* head, int broj) {
	Elem* novi = NULL;
	novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	novi->link = NULL;

	if (!head) {
		head = novi;
		return head;
	}

	Elem* pom = head;
	while (pom->link) {
		pom = pom->link;
	}
	pom->link = novi;

	return head;
}

Elem* unija(Elem* prva, Elem* druga) {
	Elem* un = NULL;

	while (prva) {
		un = naKraju(un, prva->broj);
		prva = prva->link;
	}
	while (druga) {
		un = naKraju(un, druga->broj);
		druga = druga->link;
	}

	return un;
}

int main() {
	Elem* head = NULL;
	Elem* head2 = NULL;
	Elem* un = NULL;

	head = naKraju(head, 10);
	head = naKraju(head, 15);
	head = naKraju(head, 7);
	head = naKraju(head, 3);
	head = naKraju(head, 11);
	head = naKraju(head, 9);
	head = naKraju(head, 17);
	head = naKraju(head, 23);

	head2 = naKraju(head2, 20);
	head2 = naKraju(head2, 13);

	pisi(head);
	printf("\n");

	un = unija(head, head2);
	pisi(un);
	printf("\n");

	return 0;
}