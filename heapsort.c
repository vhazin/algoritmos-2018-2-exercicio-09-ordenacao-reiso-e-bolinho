#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int array[], int i, int sizeHeap);
void heapSort(int array[], int size);
void printArray(int array[], int size);

int main(void) {

	int size, count;
	int *array;
	printf("Digite quantos elementos tera o array: ");
	scanf("%d", &size);  /* recebe o tamanho do array */
	array = malloc(size * sizeof(int));  /* aloca memória para o tamanho */
	/* rebebe os elementos do array */
	printf("Digite os elementos do array separados por espaco: ");
	for (count = 0; count < size; count++)
		scanf("%d", &array[count]);
	heapSort(array, size);
	printArray(array, size);
	return 0;
}


void maxHeapify(int array[], int i, int sizeHeap) {
	int maior;
	int left = (2*i) + 1;
	int right = (2*i) + 2;
	if (left < sizeHeap && array[left] > array[i]) {
		maior = left;
	}else {
		maior = i;
	}
	if (right < sizeHeap && array[right] > array[maior]) {
		maior = right;
	}
	if (maior != i) {
		/* swap values */
		int temp = array[i];
		array[i] = array[maior];
		array[maior] = temp;
		maxHeapify(array, maior, sizeHeap);
	}
}

void heapSort(int array[], int size) {
	int i;
	for (i = size/2-1; i >= 0; i--)
		maxHeapify(array, i, size);
	for (i = size-1; i >= 0 ; i--) {
		/* swap values */
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		maxHeapify(array, 0, i);
	}
}

void printArray(int array[], int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf(" %d ", array[i]);
		if (i != (size - 1)) {
			printf("|");
		}
	}
	printf("]");
	printf("\n");
}
