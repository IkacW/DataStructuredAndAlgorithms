//13. Napisati rekurzivnu funkciju koja će u jednostruko spregnutoj linearnoj listi prebrojati pozitivne elemente.

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

int prebroji(Elem* head) {
	Elem* pom = NULL;
	pom = head;
	if (pom == NULL) {
		return 0;
	}
	else {
		if (pom->broj > 0)
			return 1 + prebroji(pom->link);
		else
			return prebroji(pom->link);
	}
}