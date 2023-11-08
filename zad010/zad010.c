#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
	int broj;
	struct elem* link;
}Elem;

int duz(Elem* clan) {
	int n = 0;
	while (clan) {
		n++;
		clan = clan->link;
	}
	return n;
}

void pisi(Elem* clan) {
	if (!clan) {
		printf("Ne postoji nista za pisanje.");
		return;
	}
	while (clan) {
		printf("| %d |         ", clan->broj);
		clan = clan->link;
	}
}

//dodavanje elementa na pocetak liste
Elem* na_pocetak(Elem* clan, int broj) {
	Elem* novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	novi->link = clan;
	clan = novi;
	return clan;
}

// dodavanje elemnta na kraj liste
Elem* na_kraj(Elem* clan, int broj) {
	Elem* novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	novi->link = NULL;

	if (!clan) {
		return novi;
	}
	else {
		Elem* pomocni = clan;
		while (pomocni->link) 
			pomocni = pomocni->link;
		return clan;		
	}
}

Elem* ucitaj_listu_na_pocetak(int n) {
	Elem* prvi = NULL;

	for (int i = 0; i < n; i++) {
		Elem* novi = (Elem*)malloc(sizeof(Elem));
		printf("Unesite %d. broj: ", i + 1);
		scanf("%d", &novi->broj);
		novi->link = prvi;
		prvi = novi;
	}
	return prvi;
}

Elem* ucitaj_listu_na_kraj(int n) {
	Elem* prvi = NULL;
	Elem* poslednji = NULL;

	for (int i = 0; i < n; i++) {
		Elem* novi = (Elem*)malloc(sizeof(Elem));
		scanf("%d", &novi->broj);
		novi->link = NULL;

		if (!prvi) {
			prvi = novi;
		}
		else {
			poslednji->link = novi;
			
		}
		poslednji = novi;
	}

	return prvi;
}

Elem* umetni_u_uredjenu_listu(Elem* list, int broj) {
	Elem* trenutni = list, * prethodni = NULL, * novi;

	if (trenutni) {
		if (trenutni->broj >= broj) {
			return novi = na_pocetak(list, broj);
		}
	}
	else {
		return novi = na_pocetak(list, broj);
	}

	while (trenutni && trenutni->broj < broj) {
		prethodni = trenutni;
		trenutni = trenutni->link;
	}
	novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = broj;
	if (!prethodni) {
		list = novi;
	}
	else {
		prethodni->link = novi;
		novi->link = trenutni;
	}
	return list;
}

//Elem* delociraj(Elem* prvi) {
//	if (prvi == NULL) {
//		printf("Ne postoji nista za brisanje.");
//		return NULL;
//	}
//	Elem* prethodni = prvi, * tren = prvi->link;
//	while (tren->link) {
//		free(prethodni);
//		prethodni = tren;
//		tren = tren->link;
//	}
//	free(tren);
//	prvi = NULL;
//	return prvi;
//}

void delociraj(Elem** prvi) {
	Elem* stari = NULL;
	while (*prvi) {
		stari = *prvi;
		*prvi = (*prvi)->link;
		free(stari);
	}
	*prvi = NULL;
}

Elem* izostavi(Elem* prvi, int broj) {
	Elem* prethodni = prvi, * trenutni = NULL;
	while (trenutni->link) {
		if (trenutni->broj == broj) {

		}
	}
}

int main() {
	Elem* prvi = NULL;
	prvi = na_kraj(prvi, 5);
	prvi = na_pocetak(prvi, 10);
	prvi = na_kraj(prvi, 15);

	Elem* novi = NULL;
	novi = na_pocetak(novi, 2);
	novi = umetni_u_uredjenu_listu(novi, 1);
	novi = umetni_u_uredjenu_listu(novi, 4);
	novi = umetni_u_uredjenu_listu(novi, 8);
	novi = umetni_u_uredjenu_listu(novi, 5);

	pisi(prvi);
	printf("\n");
	pisi(novi);

	delociraj(&novi);

	return 0;
}