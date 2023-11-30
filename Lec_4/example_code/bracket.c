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
    char str[100];
    int i;
    int len;

    printf("Please enter a calculate expression: ");
    gets(str);      // 编译会有警告, 但只要输入的字符小于str的大小, 不越界, 就不会有问题

    len = strlen(str);
    for (i = 0; i < len; i++){
        if (str[i] == '('){         // 遍历到左括号
            push(i);
        }
        else if(str[i] == ')'){     // 遍历到右括号
            printf("%d %d\n", pop(), i);
        }
    }

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
