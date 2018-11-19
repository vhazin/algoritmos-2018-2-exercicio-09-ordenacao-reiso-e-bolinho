/*
	ALGORITMO DE ORDENAÇÃO INSERTIONSORT
*/

#include <stdio.h>
#include <time.h>

void printArrayInsertion(int array[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("%d \t", array[i]);
    printf("\n");
}

void insertionSort(int array[], int n)
{
    int j, numAtual, vezes;

    // Navega pelo Array
    for (int k = 1; k <= n - 1; k++)
    {
    
        numAtual = array[k];
        j = k - 1;

        // Confere se é neceessária a troca
        while (j >= 0 && numAtual < array[j])
        {
            vezes++;
            // Troca dos números
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = numAtual;

    }
}
void is(int array[], int tamanho)
{
    int newArray[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        newArray[i] = array[i];
    }
    int tamanho2;
    clock_t begin = clock();
    double cpu_time_used;

    insertionSort(newArray, tamanho);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de execução em segundos: %lf\n", time_spent);
}
