#include <stdio.h>
#include <stdlib.h>

#define SIZE	15
#define M	11

struct node
{
	unsigned int elem;
	struct node *next;
};

void BucketSort(int array[], int n);
void Insert_Bucket(struct node *Bucket[], int value);
int Scores_Sort(int value);
void Show_Bucket(struct node *Bucket[], int m);

int main(void)
{
	int scores[SIZE] = {66, 73, 51, 71, 85, 46, 82, 12, 73, 92, 79, 5, 70, 81, 88};
	printf("Original array: \n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", scores[i]);
	printf("\n");

	BucketSort(scores, SIZE);

	printf("After sort: \n");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", scores[i]);
	printf("\n");

	return 0;
}

void BucketSort(int array[], int n)
{
	struct node *Bucket[M] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

	for(int i = 0; i < n; i++)
		Insert_Bucket(Bucket, array[i]);

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

void Insert_Bucket(struct node *Bucket[], int value)
{
	int index = Scores_Sort(value);
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->elem = value;

	if(Bucket[index] == NULL || Bucket[index]->elem > p->elem)
	{
		p->next = Bucket[index];
		Bucket[index] = p;
	}
	else
	{
		struct node *point = Bucket[index];
		struct node *pre = NULL;
		while(point != NULL && point->elem <= p->elem)
		{
			pre = point;
			point = point->next;
		}
		pre->next = p;
		p->next = point;
	}
}

int Scores_Sort(int value)
{
	return value / 10;
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
