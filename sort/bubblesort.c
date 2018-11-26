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

void bubbleSort(int array[], int n)
{
    int i, j;
    
    // Aplicando o bubble sort
    for (i = 0; i < n - 1; i++)
    {
        // Navegando pelo array e conferindo qual é maior
        for (j = 0; j < n; j++)
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
    int newArray[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        newArray[i] = array[i];
    }

    clock_t begin = clock();
    double cpu_time_used;

    bubbleSort(newArray, tamanho);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de execução em segundos: %lf\n", time_spent);
}
