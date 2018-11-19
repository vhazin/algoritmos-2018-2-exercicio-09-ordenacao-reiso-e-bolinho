#include <stdio.h>
#include <time.h>

void quickSort2(int *vetor, int inicio, int final);
int particiona(int array[], int inicio, int fim);
void swapq2(int *a, int *b);
void printArrayQuick(int array[], int size);

void qs2(int array[], int size)
{
    int newArray[size];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    clock_t begin = clock();
    double cpu_time_used;

    quickSort2(newArray, 0, size - 1);

    clock_t end = clock();
    double time_spent2 = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de execução em segundos: %lf\n", time_spent2);

    printArrayQuick(newArray, size);
}

void quickSort2(int vetor[], int inicio, int final)
{
    if (inicio < final)
    {
        int pIndex = particiona(vetor, inicio, final);
        quickSort2(vetor, inicio, pIndex - 1);
        quickSort2(vetor, pIndex + 1, final);
    }
}

void printArrayQuick(int array[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("%d \t", array[i]);
    printf("\n");
}

int particiona(int vetor[], int inicio, int fim)
{
    int esq = inicio;
    int dir = fim;
    int pivo = vetor[inicio];
    int swap;

    while (esq <= dir)
    {
        while (vetor[esq] < pivo)
        {
            esq++;
        }
        while (vetor[dir] > pivo)
        {
            dir--;
        }
        if (esq <= dir)
        {
            swap = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = swap;
            esq++;
            dir--;
        }
    }
}