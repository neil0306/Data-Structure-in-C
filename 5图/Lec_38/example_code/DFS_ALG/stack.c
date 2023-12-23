#include "stack.h"

int stack[512];        // 用数组实现栈
int top = 0;            // 栈顶指针

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
    return top == 0;
}

int isFull(void)
{
    return top == 512;
}
