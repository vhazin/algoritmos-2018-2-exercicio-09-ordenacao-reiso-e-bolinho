#include "sort/bubblesort.c"
#include "sort/heapsort.c"
#include "sort/insertionsort.c"
#include "sort/mergesort.c"
#include "sort/selectionsort.c"
#include "sort/quicksort.c"
#include "sort/quicksort2.c"

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
    bs(array, tamanho);
    printf("\nSelection:\n");
    ss(array, tamanho);
    printf("\ninsertion:\n");
    is(array, tamanho);
    printf("\nMerge:\n");
    ms(array, tamanho);
    printf("\nheap:\n");
    hs(array, tamanho);    
    printf("\nQuickSort final:\n");
    qs(array, tamanho);
    printf("\nQuickSort inicio:\n");
    qs2(array, tamanho);
}