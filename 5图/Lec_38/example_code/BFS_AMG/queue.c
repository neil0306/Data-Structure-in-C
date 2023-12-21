#include <stdio.h>
#include "queue.h"

int queue[SIZE];

int head = 0, tail = 0;     // 空队列头尾指针相同

void enqueue(int n)
{
    queue[tail] = n;
    tail = (tail + 1) % SIZE;
}

int dequeue(void)
{
    int n;
    n = queue[head];
    head = (head + 1) % SIZE;
    return n;
}

int isEmpty()
{
    return head == tail;
}

int isFull()
{
    return (tail+1) % SIZE == head;
}

