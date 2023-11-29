#include <stdio.h>

#define SIZE	10

void Divide_MergeSort(int array[], int start, int end);
void MergeSort(int array[], int start, int mid, int end);

int main(void)
{
	int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};
	printf("Original array:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	Divide_MergeSort(arr, 0, SIZE - 1);

	printf("After sort:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");


	return 0;
}

void Divide_MergeSort(int array[], int start, int end)
{
	int mid;
	if(start < end)
	{
		mid = (start + end) / 2;
		Divide_MergeSort(array, start, mid);
		Divide_MergeSort(array, mid+1, end);
		MergeSort(array, start, mid, end);
	}
}

void MergeSort(int array[], int start, int mid, int end)
{
	int i, j, k;

	int n1 = mid - start + 1;
	int n2 = end - mid;

	int left[n1];
	int right[n2];

	for(i = 0; i < n1; i++)
		left[i] = array[start + i];
	for(j = 0; j < n2; j++)
		right[j] = array[mid+1 + j];

	i = j = 0;
	k = start;

	while(i < n1 && j < n2)
	{
		if(left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while(i < n1)
		array[k++] = left[i++];
	while(j < n2)
		array[k++] = right[j++];
}
