#include <stdio.h>
#include <time.h>

void quicksort(int thearray[], int start, int end);
int partition(int thearray[], int start, int end);
void swapQuick(int *firstnum, int *secondnum);

void qs(int array[], int size)
{
	int newArray[size];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
	clock_t begin = clock();
	double cpu_time_used;

	quicksort(newArray, 0, size - 1);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tempo de execução em segundos: %lf\n", time_spent);
}

void quicksort(int thearray[], int start, int end)
{
	if (start < end)
	{
		/* get the partition index and make the recursion */
		int pIndex = partition(thearray, start, end);
		quicksort(thearray, start, pIndex - 1);
		quicksort(thearray, pIndex + 1, end);
	}
}

int partition(int thearray[], int start, int end)
{
	/* gets the pivot */
	int pivot = thearray[end];
	/* partition index */
	int pIndex = start;
	for (int i = start; i < end; i++)
	{
		if (thearray[i] <= pivot)
		{
			swapQuick(&thearray[i], &thearray[pIndex]);
			pIndex++;
		}
	}
	swapQuick(&thearray[pIndex], &thearray[end]);
	return pIndex;
}

void swapQuick(int *firstnum, int *secondnum)
{
	int swapper = *firstnum;
	*firstnum = *secondnum;
	*secondnum = swapper;
}

