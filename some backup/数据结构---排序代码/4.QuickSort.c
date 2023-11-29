#include <stdio.h>

#define SIZE	10

void QuickSort(int array[], int start, int end);

int main(void)
{
	int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
	printf("Original array:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	QuickSort(arr, 0, SIZE - 1);

	printf("After sort:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}

void QuickSort(int array[], int start, int end)
{
	int i = start;
	int j = end;
	int tmp;

	while(i < j)
	{
		while(array[i] < array[j] && i < j)
			j--;
		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;

		while(array[i] <= array[j] && i < j)
			i++;
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}

	if(i - 1 > start)
		QuickSort(array, start, i-1);
	if(i + 1 < end)
		QuickSort(array, i+1, end);
}
