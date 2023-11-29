#include <stdio.h>
#include <stdlib.h>

#define SIZE	16
#define M	10

struct node
{
	unsigned int elem;
	struct node *next;
};

void RadixSort(int array[], int n);
int Search_Maxbit(int array[], int n);
int Bitnumber(int x, int bit);
void Show_Bucket(struct node *Bucket[], int m);

int main(void)
{
	int scores[SIZE] = {66, 73, 51, 71, 85, 46, 82, 12, 73, 92, 79, 5, 70, 81, 88, 100};
	printf("Original array: \n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", scores[i]);
	printf("\n");

	RadixSort(scores, SIZE);

	printf("After sort: \n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", scores[i]);
	printf("\n");

	return 0;
}

void RadixSort(int array[], int n)
{
	int maxbit;
	maxbit = Search_Maxbit(array, n);

	for(int k = 1; k <= maxbit; k++)
	{
		struct node *Bucket[M] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
		for(int i = 0; i < n; i++)
		{
			int index = Bitnumber(array[i], k);   //1:234(4)  2:234(3) 3:234(2)
			struct node *p = (struct node *)malloc(sizeof(struct node));
			p->elem = array[i];
			if(Bucket[index] == NULL)
			{
				Bucket[index] = p;
				p->next = NULL;
			}
			else
			{
				struct node *point = Bucket[index];
				struct node *pre = NULL;
				while(point != NULL)
				{
					pre = point;
					point = point->next;
				}
				pre->next = p;
				p->next = point;
			}
		}
		//Show_Bucket(Bucket, M);
		for(int i = 0, j = 0; i < M; i++)
		{
			struct node *point = Bucket[i];
			if(point == NULL)
				continue;
			while(point != NULL)
			{
				array[j] = point->elem;
				point = point->next;
				j++;
			}
		}
	}
}

int Search_Maxbit(int array[], int n)
{
	int max = array[0];
	int digits = 0;

	for(int i = 1; i < n; i++)
	{
		if(array[i] > max)
			max = array[i];
	}

	while(max != 0)
	{
		digits++;
		max /= 10;
	}

	return digits;
}
//bit:  1:g  2:s  3:b
int Bitnumber(int x, int bit)
{
	int temp = 1;
	for(int i = 1; i < bit; i++)
		temp *= 10;

	return (x / temp) % 10;
}

void Show_Bucket(struct node *Bucket[], int m)
{
	struct node *p;
	for(int i = 0; i < m; i++)
	{
		printf("Bucket index %d has: ", i);
		for(p = Bucket[i]; p != NULL; p = p->next)
			printf("%d ", p->elem);
		printf("\n");
	}
}
