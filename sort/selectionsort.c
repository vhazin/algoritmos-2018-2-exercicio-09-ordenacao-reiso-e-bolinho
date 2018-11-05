/*
	ALGORITMO DE ORDENAÇÃO SELECTIONSORT
*/

#include <stdio.h>
#include <time.h>

void swapSelection(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função do print do Array
void printArraySelection(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void selectionSort(int array[], int n)
{
    int min, trocou = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[min] > array[j])
            {
                min = j;
                trocou = 1;
            }
        }
        if (trocou)
        {
            swapSelection(&array[min], &array[i]);
        }
    }
}

void rs(int array[], int tamanho)
{
    clock_t begin = clock();
	double cpu_time_used;

    selectionSort(array, tamanho);
    clock_t end = clock();
	double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Tempo de execução em segundos: %lf\n", time_spent);

}