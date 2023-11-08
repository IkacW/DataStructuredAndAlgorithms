

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
}

void pisi(Elem* head) {
	while (head) {
		printf("|   %d   |  ", head->broj);
		head = head->link;
	}
}

Elem* upisi(FILE* f) {
	Elem* head = NULL;
	Elem* novi = NULL;
	Elem* posl = NULL;

	while (!feof(f)) {
		novi = (Elem*)malloc(sizeof(Elem));
		fscanf(f, "%d", &novi->broj);
		novi->link = NULL;

		if (head == NULL) {
			head = novi;
		}
		else {
			posl->link = novi;
		}
		posl = novi;
	}
	return head;
}

int duzina(Elem* head) {
	int n = NULL;
	while (head) {
		n++;
		head = head->link;
	}
	return n;
}

int* napraviNiz(Elem* head) {
	int* niz = NULL;
	int n = duzina(head);
	niz = (int*)calloc(n, sizeof(int));

	int i = 0;
	while (head) {
		niz[i] = head->broj;

		head = head->link;
		i++;
	}

	printf("\n{");
	for (int i = 0; i < n; i++) {
		printf(" %d ", niz[i]);
	}
	printf("}\n");

	return niz;
}

//void ispisiNiz(int* niz) {
//	int i = 0;
//	printf("{");
//	while (niz) {
//		printf(" %d ", niz[i]);
//
//		i++;
//	}
//	printf("}\n");
//}

int main() {
	Elem* head = NULL;
	int* niz = NULL;

	FILE* f = fopen("zad020.txt", "r");
	head = upisi(f);
	fclose(f);

	pisi(head);
	printf("\nDuzina:%d\n", duzina(head));

	niz = napraviNiz(head);


	return 0;
}
