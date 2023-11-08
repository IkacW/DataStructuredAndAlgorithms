#include <stdlib.h>
#include <stdio.h>

int main() {
	int* ptr = (int*)malloc(2 * sizeof(int));
	int* ptr1 = (int*)calloc(2, sizeof(int));

	for (int i = 0; i < 2; i++) {
		printf("%d ", *(ptr + i));
	}

	printf("\n");

	for (int i = 0; i < 2; i++) {
		printf("%d ", *(ptr1 + i));
	}

	return 0;
}