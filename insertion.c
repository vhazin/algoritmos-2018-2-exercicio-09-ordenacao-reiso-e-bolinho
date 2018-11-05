#include <stdio.h>

void printArray(int array[], int size)
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
        printf("\n");
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

        printf("Troca: %d", vezes);
        array[j + 1] = numAtual;
        vezes = 0;
    }
    printf("\n");
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
    insertionSort(array, tamanho);
    printf("\nArray ordenado:\n ");
    printArray(array, tamanho);
    return 0;
}
