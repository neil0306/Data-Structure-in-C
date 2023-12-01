#include <stdio.h>
#include <string.h>

char stack[512];        // 用数组实现栈
int top = 0;            // 栈顶指针

void push(char c);
char pop(void);
int isEmpty(void);
int isFull(void);

int is_palindrom(const char *pt);

int main(void)
{
    char str[100];
    printf("Please enter a string: ");
    gets(str);

    if (is_palindrom(str)){
        printf("string is a palindrom.\n");
    }
    else{
        printf("string is NOT a palindrom.\n");
    }

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
    return top == 0;
}

int isFull(void)
{
    return top == 512;
}

int is_palindrom(const char *pt)
{
    int len, i;
    len = strlen(pt);
    for (i = 0; i < len/2; i++){
        push(pt[i]);
    }
    if(len % 2 == 1){
        i++;
    }
    while(!isEmpty()){
        if (pop() == pt[i]){
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}
