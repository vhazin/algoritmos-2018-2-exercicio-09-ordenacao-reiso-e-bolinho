/*
	ALGORITMO DE ORDENAÇÃO MERGESORT
*/
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int array[], int length);
void merge(int left[], int right[], int array[], int sizeLeft, int sizeRight, int sizeArray);
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
	/* checa se o array tem menos de dois elementos, se tiver ja esta ordenado */
	printf("\n");
	if (size < 2) {
		printf("Array ja esta ordenado\n");
		return 0;
	}

	mergeSort(array, size);
	/* printa o array */
	printf("Array ordenado: \n");
	printArray(array, size);

	return 0;
}

void mergeSort(int array[], int length) {
	if (length < 2) {
		return;
	}
	int i;
	int mid = (length / 2);
	int left[mid];
	int right[length - mid];
	/* separa e copia do array original */
	/* copia do começo até a metade */
	for (i = 0; i < (mid); i++)
		left[i] = array[i];
	/* copia da metade até o fim */
	for (i = mid; i < (length); i++)
		right[i - mid] = array[i];
	mergeSort(left, mid);
	mergeSort(right, (length - mid));
	merge(left, right, array, (mid), (length - mid), length);
}

void merge(int left[], int right[], int array[], int sizeLeft, int sizeRight, int sizeArray) {
	int indexLeft = 0;
	int indexRight = 0;
	int indexArray = 0;
	/* ordena */
	while (indexLeft < sizeLeft && indexRight < sizeRight) {
		if (left[indexLeft] <= right[indexRight]) {
			array[indexArray] = left[indexLeft];
			indexArray++;
			indexLeft++;
		}else {
			array[indexArray] = right[indexRight];
			indexArray++;
			indexRight++;
		}
	}
	/* se o arrary da direita completar primeiro */
	while (indexLeft < sizeLeft) {
		array[indexArray] = left[indexLeft];
		indexArray++;
		indexLeft++;
	}
	/* se o array da esquerda completar primeiro */
	while (indexRight < sizeRight) {
		array[indexArray] = right[indexRight];
		indexArray++;
		indexRight++;
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
