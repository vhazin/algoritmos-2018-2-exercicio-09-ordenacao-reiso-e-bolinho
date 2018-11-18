#include <stdio.h>

void quicksort(int thearray[], int start, int end);
int partition(int thearray[], int start, int end);
void swap(int *firstnum, int *secondnum);
void printArray(int thearray[], int size);

int main() {

	int sizeofarray;
	printf("Digite o numero de elementos do array: ");
	scanf("%d", &sizeofarray);
	int myarray[sizeofarray];
	printf("Digite os elementos do array: ");
	for (int i = 0; i < sizeofarray; i++)
		scanf("%d", &myarray[i]);
	/* runs the quicksort */
	quicksort(myarray, 0, sizeofarray-1);
	printArray(myarray, sizeofarray);
	return 0;
}

void quicksort(int thearray[], int start, int end) {
	if (start < end) {
		/* get the partition index and make the recursion */
		int pIndex = partition(thearray, start, end);
		quicksort(thearray, start, pIndex-1);
		quicksort(thearray, pIndex+1, end);
	}
}

int partition(int thearray[], int start, int end) {
	/* gets the pivot */
	int pivot = thearray[end];
	/* partition index */
	int pIndex = start;
	for (int i = start; i < end; i++) {
		if (thearray[i] <= pivot) {
			swap(&thearray[i], &thearray[pIndex]);
			pIndex++;
		}
	}
	swap(&thearray[pIndex], &thearray[end]);
	return pIndex;
}

void swap(int *firstnum, int *secondnum) {
	int swapper = *firstnum;
    *firstnum = *secondnum;
    *secondnum = swapper;
}

void printArray(int thearray[], int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf(" %d ", thearray[i]);
		if (i != (size - 1)) {
			printf("|");
		}
	}
	printf("]");
	printf("\n");
}
