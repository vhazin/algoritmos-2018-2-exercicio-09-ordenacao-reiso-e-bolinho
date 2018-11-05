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
            swap(&array[min], &array[i]);
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
    printf("\nArray desordenado:\n ");
    printArray(array, tamanho);
    selectionSort(array, tamanho);
    printf("\nArray ordenado:\n ");
    printArray(array, tamanho);
    return 0;
}