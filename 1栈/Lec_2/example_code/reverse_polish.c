#include <stdio.h>
#include <string.h>

int stack[512];        // 用数组实现栈
int top = 0;            // 栈顶指针

void push(int c);
int pop(void);
int isEmpty(void);
int isFull(void);

int main(void)
{
    char a[100];
    int n;
    int i;
    int n1, n2;

    printf("Please enter a reverse polish expression: \n");
    gets(a);        // 这个函数输入有风险, 但只要不越界, 就还行
    n = strlen(a);

    for (i = 0; i < n; i++){
        if (a[i] >= '0' && a[i] <= '9'){  // 输入操作数时, 目前只考虑个位数
            push(a[i] - '0');
        }
        else{   
            // 注意出栈顺序, 这会影响计算结果. 由于栈是后入先出, 所以先出栈的是第二个操作数, 第一个操作数排在后面
            n2 = pop();
            n1 = pop();
            switch (a[i])       // 根据不同操作符执行不同的出栈操作
            {
            case '+':
                push(n1 + n2);
                break;
            case '-':
                push(n1 - n2);
                break;
            case '*':
                push(n1 * n2);
                break;
            default:
                break;
            }
        }
    }
    printf("result = %d\n", pop());

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
    return top == 0;
}

int isFull(void)
{
    return top == 512;
}
