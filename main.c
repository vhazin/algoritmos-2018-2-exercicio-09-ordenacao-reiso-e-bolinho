#include "sort/bubblesort.c"
#include "sort/heapsort.c"
#include "sort/insertionsort.c"
#include "sort/mergesort.c"
#include "sort/selectionsort.c"

int main(){
    int tamanho;
    printf("tamanho do array: ");
    scanf("%d", &tamanho);
    int array[tamanho];

    printf("Digite os elementos do array separados por espaco: ");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("bubble:\n");
    rb(array, tamanho);
    printf("\nheap:\n");
    rh(array, tamanho);
    printf("\ninsertion:\n");
    ri(array, tamanho);
    printf("\nMerge:\n");
    rm(array, tamanho);
    printf("\nSelection:\n");
    rs(array, tamanho);
}