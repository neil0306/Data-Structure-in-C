#include <stdio.h>
#include <string.h>

char stack[512];        // 用数组实现栈
int top = 0;            // 栈顶指针

void push(char c);
char pop(void);
int isEmpty(void);
int isFull(void);

int main(void)
{
    char str[100];
    int i, len;
    printf("Please enter a calculate expression: \n");
    gets(str);

    len = strlen(str);
    for (i = 0; i < len; i++){
        if (str[i] == '('){
            continue;
        }
        else if (str[i] >= '0' && str[i] <= '9'){
            printf("%c", str[i]);
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*'){
            push(str[i]);
        }
        else if(str[i] == ')'){
            printf("%c", pop());
        }
    }
    printf("\n");

    return 0;
}

void push(char c)
{
    if (!isFull()){
        stack[top++] = c;   // top++ 表示在执行完这行代码后自增1
    }
}

char pop(void)
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
