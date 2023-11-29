#include <stdio.h>

#define SIZE	10

void HeapSort(int array[], int n);  //n == maxindex
void Sink(int array[], int k, int n);
void swap(int *p1, int *p2);

int main(void)
{
	int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
	printf("Original array:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	HeapSort(arr, SIZE - 1);

	printf("After sort:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void HeapSort(int array[], int n)
{
	for(int i = (n-1)/2; i >= 0; i--)
		Sink(array, i, n);

	while(n > 0)
	{
		swap(&array[0], &array[n--]);
		Sink(array, 0, n);
	}
/*
	for(int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);
	printf("\n");
*/
}

void Sink(int array[], int k, int n)
{
	while((2*k+1) <= n)
	{
		int j = 2*k + 1;
		if(j < n && array[j] < array[j+1])
			j++;
		if(array[k] >= array[j])
			break;
		else
			swap(&array[k], &array[j]);

		k = j;
	}
}

void swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
