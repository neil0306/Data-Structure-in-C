#include <stdio.h>

#define SIZE 512
char queue[SIZE];
int head = 0, tail = 0;     // 空队列头尾指针相同

void enqueue(char c);
char dequeue(void);
int isEmpty();
int isFull();

int main(void)
{
    char c = 'A';
    int i;

    // 入队列
    for (i = 0; i < 3; i++)
    {
        if(!isFull()){
            enqueue(c);
            c++;            // 编程 ASCII 码之后, ++ 操作就会顺延一个字符, 变成 B
        }
    }

    // 出队列
    while(!isEmpty()){
        printf("%c", dequeue());
    }
    printf("\n");

    return 0;
}

void enqueue(char c)
{
    queue[tail] = c;
    tail = (tail + 1) % SIZE;
}

char dequeue(void)
{
    char ch;
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
