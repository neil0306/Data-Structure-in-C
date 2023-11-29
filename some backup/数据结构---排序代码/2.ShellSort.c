#include <stdio.h>

#define SIZE	10
#define MAX	100

void ShellSort(int array[], int n);
void ShellInsertSort(int array[], int n, int d);

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
	ShellSort(sort, SIZE);
	for(int i = 0; i < SIZE; i++)
		arr[i] = sort[i+1];

	printf("After sort:\n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void ShellSort(int array[], int n)
{
	int count;

	printf("Please enter the number of increment:\n");
	scanf("%d", &count);
	int inc[count];
	printf("Please enter %d increment:\n", count);
	for(int i = 0; i < count; i++)
		scanf("%d", &inc[i]);

	for(int i = 0; i < count; i++)
	{
		ShellInsertSort(array, n, inc[i]);
		for(int i = 1; i <= n; i++)
			printf("%d ", array[i]);
		printf("\n");
	}
}

void ShellInsertSort(int array[], int n, int d)
{
	int i, j;

	for(i = 1+d; i <= n; i++)   //(i = 2, 1 + 1)
	{
		if(array[i] < array[i-d])
		{
			array[0] = array[i];
			array[i] = array[i-d];
			for(j = i-d-d; j>0 && array[j] > array[0]; j -= d)
				array[j+d] = array[j];
			array[j+d] = array[0];
		}
	}
}
