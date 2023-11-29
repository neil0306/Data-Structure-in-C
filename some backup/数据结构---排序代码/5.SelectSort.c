#include <stdio.h>

#define SIZE	10

void SimpleSelectSort(int array[], int n);

int main(void)
{
	int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
	printf("Original array:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	SimpleSelectSort(arr, SIZE);

	printf("After sort:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}

void SimpleSelectSort(int array[], int n)
{
	int i, j, min;
	int temp;

	for(i = 0; i < n-1; i++)
	{
		min = i;
		for(j = i+1; j < n; j++)
		{
			if(array[j] < array[min])
				min = j;
		}
		if(min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}
