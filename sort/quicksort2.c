#include <stdio.h>
#include <time.h>

void quickSort2(int array[], int inicio, int final);
int particiona(int array[], int inicio, int fim);
void swapq2(int *a, int *b);

void qs2(int myarray[], int sizeArray)
{
    clock_t begin = clock();
	double cpu_time_used;

	quickSort2(myarray, 1, sizeArray - 1);

	clock_t end = clock();
	double time_spent2 = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tempo de execução em segundos: %lf\n", time_spent2);
}

void quickSort2(int *a, int inicio, int final)
{
    int i, j, x, y;
     
    i = inicio;
    j = final;
    x = a[(inicio + final) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < inicio) {
            i++;
        }
        while(a[j] > x && j > final) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > final) {
        quickSort2(a, final, j);
    }
    if(i < inicio) {
        quickSort2(a, i, inicio);
    }
}

