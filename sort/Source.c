#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

void fromFile(int* a, char* filename, int n) {
	FILE* f = fopen(filename, "r");
	fscanf(f, "%d", &n);

	int i = 0;
	while (!feof(f)) {
		fscanf(f, "%d", (a + i));
		i++;
	}
}

void printArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
}

int main() {
	int* a = NULL;
	FILE* f = fopen("sort.txt", "r");

	int n = 0;
	fscanf(f, "%d", &n);

	a = (int*)calloc(n, sizeof(int));

	fclose(f);

	fromFile(a, "sort.txt", n);

	printArray(a, n);

	return 0;
}