#include <stdio.h>

void swap(int *a, int *b)
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
        printArray(array, n);
        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main()
{
    int tamanho;
    printf("tamanho do array: ");
    scanf("%d", &tamanho);
    int array[tamanho];

    printf("Digite os elementos do array separados por espaco: ");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &array[i]);
    }
    bubbleSort(array, tamanho);
    printf("Array ordenado: \n");
    printArray(array, tamanho);
    return 0;
}
