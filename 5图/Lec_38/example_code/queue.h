#ifndef __GRAPH_QUEUE_H__
#define __GRAPH_QUEUE_H__

#include <stdio.h>
#define SIZE 512
void enqueue(int n);
int dequeue(void);
int isEmpty();
int isFull();

extern int queue[SIZE];

#endif //! __GRAPH_QUEUE_H__