/*
	ALGORITMO DE ORDENAÇÃO HEAPSORT
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void maxHeapify(int array[], int i, int sizeHeap);
void heapSort(int array[], int size);
void printArrayHeap(int array[], int size);

void hs(int array[], int size)
{
	clock_t begin = clock();
	double cpu_time_used;

	int count;
	
	heapSort(array, size);
	clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Tempo de execução em segundos: %lf\n", time_spent);
}

void maxHeapify(int array[], int i, int sizeHeap)
{
	int maior;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	if (left < sizeHeap && array[left] > array[i])
	{
		maior = left;
	}
	else
	{
		maior = i;
	}
	if (right < sizeHeap && array[right] > array[maior])
	{
		maior = right;
	}
	if (maior != i)
	{
		/* swap values */
		int temp = array[i];
		array[i] = array[maior];
		array[maior] = temp;
		maxHeapify(array, maior, sizeHeap);
	}
}

void heapSort(int array[], int size)
{
	int i;
	for (i = size / 2 - 1; i >= 0; i--)
		maxHeapify(array, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		/* swap values */
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		maxHeapify(array, 0, i);
	}
}

void printArrayHeap(int array[], int size)
{
	printf("[");
	for (int i = 0; i < size; i++)
	{
		printf(" %d ", array[i]);
		if (i != (size - 1))
		{
			printf("|");
		}
	}
	printf("]");
	printf("\n");
}
