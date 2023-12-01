#include <stdio.h>
#include <string.h>

#define SIZE 512
char queue[SIZE];
int head = 0, tail = 0;     // 空队列头尾指针相同

void tail_enqueue(char c);
char tail_dequeue(void);
void head_enqueue(char c);
char head_dequeue(void);
int isEmpty();
int isFull();

int is_palindrom(char *pt);

int main(void)
{
    char str[100];
    printf("Please enter a string: ");
    gets(str);

    if (is_palindrom(str)){
        printf("str is a palindrom.");
    }
    else{
        printf("str is NOT a palindrom.");
    }
    printf("\n");

    return 0;
}

void tail_enqueue(char c)
{
    queue[tail] = c;
    tail = (tail + 1) % SIZE;
}

char tail_dequeue(void)
{
    tail = (tail - 1 + SIZE) % SIZE;    // 先移动指针, 确保指针指向的位置有元素
    return queue[tail];                 // 取出元素
}

void head_enqueue(char c)
{
    head = (head - 1 + SIZE) % SIZE;   // 先将指针移动到可以存放元素的位置
    queue[head] = c;                   // 存入队列
}

char head_dequeue(void)
{
    char ch = queue[head];              // 先取出元素
    head = (head + 1) % SIZE;           // 再移动指针
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

int is_palindrom(char *pt)
{
    int i, len;
    char c1, c2;        // 用于存储待比较的字符
    len = strlen(pt);
    // 所有元素入队列
    for (i = 0; i < len; i++){
        if(!isFull()){
            tail_enqueue(pt[i]);
        }
    }

    // 出队列 & 比较
    while(!isEmpty()){          // 偶数个元素会在这一步退出
        c1 = head_dequeue();    
        if(!isEmpty()){         // 奇数个元素会在一步退出
            c2 = tail_dequeue();
        }
        else{
            break;
        }

        // 判断当前字符
        if (c1 == c2){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}