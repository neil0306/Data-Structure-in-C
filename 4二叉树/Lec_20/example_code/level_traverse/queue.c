#include "queue.h"

int head = 0, tail = 0;     // 空队列头尾指针相同

void enqueue(struct BinTree_node c)
{
    queue[tail] = c;
    tail = (tail + 1) % SIZE;
}

struct BinTree_node dequeue(void)
{
    struct BinTree_node ch;
    ch = queue[head];
    head = (head + 1) % SIZE;
    return ch;
}

int isEmpty()
{
    return head == tail;
}

int isFull()
{
    return (tail+1) % SIZE == head;
}
