#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>	

typedef struct turnir {
	int sifra_turnira;
	int broj_pobeda;
	struct turnir* link
}Teniser;

Teniser* dodaj(Teniser* head, int sifra_turnira, int broj_pobeda) {
	Teniser* novi = (Teniser*)malloc(sizeof(Teniser));
	novi->broj_pobeda = broj_pobeda;
	novi->sifra_turnira = sifra_turnira;
	novi->link = head;
	head = novi;
	return head;
}

int brojPobeda(Teniser* head) {
	if (head == NULL)
		return 0;
	return head->broj_pobeda + brojPobeda(head->link);
}