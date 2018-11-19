/*
	ALGORITMO DE ORDENAÇÃO BUBBLESORT
*/

#include <stdio.h>
#include <time.h>

void swapBuble(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função do print do Array
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// A funçãoo que implementa o bubble sort
void bubbleSort(int array[], int n)
{
    int i, j;
    // Navegando pelo array e conferindo qual é maior
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swapBuble(&array[j], &array[j + 1]);
            }
        }
    }
}

void bs(int array[], int tamanho)
{
    clock_t begin = clock();
    double cpu_time_used;

    bubbleSort(array, tamanho);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de execução em segundos: %lf\n", time_spent);
}
