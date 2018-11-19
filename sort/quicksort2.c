#include <stdio.h>
#include <time.h>

void quickSort2(int *vetor, int inicio, int final);
int particiona(int array[], int inicio, int fim);
void swapq2(int *a, int *b);

void qs2(int array[], int size)
{
    int newArray[size];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    clock_t begin = clock();
	double cpu_time_used;

	quickSort2(newArray, 1, size - 1);

	clock_t end = clock();
	double time_spent2 = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tempo de execução em segundos: %lf\n", time_spent2);
}

void quickSort2(int *vetor, int inicio, int final)
{
    int esq, dir, pivo, swap;
     
    esq = inicio;
    dir = final;
    pivo = vetor[(inicio + final) / 2];
     
    while(i <= j) {
        while(vetor[esq] < pivo && esq < inicio) {
            esq++;
        }
        while(vetor[dir] > pivo && dir > final) {
            dir--;
        }
        if(esq <= dir) {
            swap = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = swap;
            esq++;
            dir--;
        }
    }
     
    if(dir > final) {
        quickSort2(vetor, final, dir);
    }
    if(esq < inicio) {
        quickSort2(vetor, esq, inicio);
    }
}

