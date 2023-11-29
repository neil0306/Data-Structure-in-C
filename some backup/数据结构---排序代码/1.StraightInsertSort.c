#include <stdio.h>

#define SIZE	10
#define MAX	100

void StraightInsertSort(int array[], int n);

int main(void)
{
	int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
	printf("Original array:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	int sort[MAX + 1];
	for(int i = 0; i < SIZE; i++)
		sort[i+1] = arr[i];
	StraightInsertSort(sort, SIZE);
	for(int i = 0; i < SIZE; i++)
		arr[i] = sort[i+1];

	printf("After sort:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void StraightInsertSort(int array[], int n)
{
	int i, j;

	for(i = 2; i <= n; i++)
	{
		if(array[i] < array[i-1])
		{
			array[0] = array[i];
			array[i] = array[i-1];
			for(j = i - 2; array[j] > array[0]; j--)
				array[j+1] = array[j];
			array[j+1] = array[0];
		}
	}
}
