/*
Napisati program koji dodaje čvor u listi nakon čvora sa zadatom vrednošću.
U prvom redu datoteke zad1.in je zadat broj n koji označava broj elemenata liste.
U narednih n redova je dato n celih brojeva koji će predstavljati elemente liste.
U narednom redu je zadat broj m iza čijeg prvog pojavljivanja je potrebno dodati
broj k koji se nalazi u poslednjem redu datoteke. Ukoliko se broj m ne nalazi u listi,
broj k dodati na početak liste. Rezultujuću listu zapisati u datoteku zad1.out.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>	
#include <stdlib.h>
#include <stdbool.h>

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

Elem* naKraj(Elem* head, int broj) { //SAMO ZA POTREBE OVOG ZADATKA, ZNAMO DA NIKAD NECE DOCI PRAZNA LISTA!!!
	Elem* pom = head;
	Elem* novi = NULL;
	novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	novi->link = NULL;

	while (pom->link) {
		pom = pom->link;
	}
	pom->link = novi;

	return head;
}

Elem* upisi(FILE* f, int* m, int* k) {
	Elem* head = NULL;
	Elem* novi = NULL;
	Elem* poslednji = NULL;
	int n;
	fscanf(f, "%d", &n);

	for (int i = 0; i < n; i++) {
		novi = (Elem*)malloc(sizeof(Elem));
		fscanf(f, "%d", &novi->broj);
		novi->link = NULL;
		if (!head) 
			head = novi;
		else 
			poslednji->link = novi;
		poslednji = novi;
	}

	//citanje m i k, da ne bi implementirali funkciju koja ce opet prolaziti n + 1 puta da bi ucitala m i k
	fscanf(f,"%d", m);
	fscanf(f, "%d", k);

	return head;
}

Elem* dodaj(Elem* head, int m, int k) {
	bool found = false;
	Elem* pomocni = head;
	Elem* novi = NULL;

	if (!head) {
		printf("GRESKA!");
		exit(EXIT_FAILURE);
	}

	while (pomocni) {
		if (pomocni->broj == m) {
			found = true;
			novi = (Elem*)malloc(sizeof(Elem));
			novi->broj = k;
			novi->link = pomocni->link;
			pomocni->link = novi;
			pomocni = pomocni->link->link;
		}
		else {
			pomocni = pomocni->link;
		}
	}
	if (found == false) {
		novi = (Elem*)malloc(sizeof(Elem));
		novi->broj = k;
		novi->link = head;
		head = novi;
	}

	return head;
}

void upisiUFajl(Elem* head, FILE* f) {
	while (head) {
		fprintf(f, "%d ", head->broj);
		head = head->link;
	}
}

int main() {
	Elem* head = NULL;
	Elem* dodat = NULL;
	int m, k;
	FILE* f = fopen("zad022.txt", "r");

	head = upisi(f, &m, &k);
	printf("%d %d\n", m, k);
	fclose(f);
	pisi(head);
	printf("\n");

	dodat = dodaj(head, m, k);
	pisi(dodat);

	FILE* f2 = fopen("Wzad020.txt", "w");
	upisiUFajl(dodat, f2);
	fclose(f2);

	printf("\n");

	return 0;
}