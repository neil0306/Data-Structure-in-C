#include <stdio.h>
#include <string.h>

#define SIZE 512
char queue[SIZE];
int head = 0, tail = 0;     // 空队列头尾指针相同

void enqueue(char c);
char dequeue(void);
int isEmpty();
int isFull();

int main(void)
{
    char code[SIZE];    // 存放用户输入的数组, 同时也是结果数组
    int i = 0;          // 重新存入队列使用的起始指针
    int n;
    char num;
    printf("Please enter a code: ");
    gets(code);
    // 把用户给的字符串全部入队列
    for (n = 0; n < strlen(code); n++){
        if (!isFull()){
            enqueue(code[n]);
        }
    }

    // 按规则出队列: 奇数位置直接出队; 偶数位置先出队, 再重新入队
    while(!isEmpty()){
        code[i++] = dequeue();  // 奇数位置: 直接出队, 并放入结果数组(这里复用了code)
        if(!isEmpty()){         // 偶数位置:
            num = dequeue();        // 1. 先出队 
            if(!isFull()){                  // 这个条件其实也可以不写, 因为前面有元素出来了, 就一定不满, 为了清晰, 这里写上
                enqueue(num);       // 2. 再重新入队
            }
        }
    }

    printf("Original code should be: ");
    for (i = 0; i < strlen(code); i++){
        printf("%c", code[i]);
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
