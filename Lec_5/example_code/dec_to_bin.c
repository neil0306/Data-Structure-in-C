#include <stdio.h>

int stack[512];        // 用数组实现栈
int top = 0;            // 栈顶指针

void push(int c);
int pop(void);
int isEmpty(void);
int isFull(void);

int main(void)
{
    int num;
    printf("Please enter an integer in decimal: \n");
    scanf("%d", &num);

    while (num != 0){
        push(num % 2);
        num /= 2;
    }

    while(!isEmpty()){
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}

void push(int c)
{
    if (!isFull()){
        stack[top++] = c;   // top++ 表示在执行完这行代码后自增1
    }
}

int pop(void)
{
    return stack[--top];    // --top 表示先自减1, 然后执行这行代码
}

int isEmpty(void)
{
    // if (top == 0){
    //     return 1;       // 1 为 true
    // }
    // else{
    //     return 0;       // 0 为 false
    // }

    return top == 0;
}

int isFull(void)
{
    return top == 512;
}
