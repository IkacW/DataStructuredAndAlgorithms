/*
Napisati funkciju koja ispisuje elemente zadate sortirane liste 
(u koju se zapisuju celi brojevi int) koji su manji od zadatog broja n. 
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
	Elem* novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	novi->link = head;
	head = novi;

	return head;
}

Elem* upisiSortirano(Elem* head, int broj) {
	Elem* tren = head, * pret = NULL;
	Elem* novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	novi->link = NULL;
	while (tren && tren->broj < broj) {
		pret = tren;
		tren = tren->link;
	}
	novi->link = tren;
	if (!pret) {
		head = novi;
		return head;
	}
	else {
		pret->link = novi;
	}
	return head;
}

//Elem* umetni(Elem* lst, int b) {
//	/* Umetanje u uredjenu
//		listu. */
//		Elem * tek = lst, *pret = NULL, *novi;
//	while (tek && tek->broj < b) {
//		pret = tek;
//		tek = tek->link;
//	}
//	novi = malloc(sizeof(Elem));
//	novi->broj = b;
//	novi->link = tek;
//	if (!pret)
//		lst = novi;
//	else pret->link = novi;
//	return lst;
//}
Elem* umetniUzUslov(Elem* head, int n) {
	int unos = 0; int brojac = 0;
	while (unos >= 0) {
		printf("Unesite %d. element:", brojac);
		scanf("%d", &unos);
		if (unos < n) {
			head = upisiSortirano(head, unos);
		}
	}

	return head;
}

void pisi(Elem* head) {
	if (head == NULL) {
		printf("Lista nema elemenata");
		return;
	}
	while (head) {
		printf("| %d |   ", head->broj);
		head = head->link;
	}
}

int main() {
	Elem* head = NULL;

	head = upisiSortirano(head, 19);
	head = upisiSortirano(head, 15);
	head = upisiSortirano(head, 20);
	head = upisiSortirano(head, 1);
	head = upisiSortirano(head, 10);
	head = upisiSortirano(head, 7);
	head = upisiSortirano(head, 12);

	pisi(head);

	return 0;
}