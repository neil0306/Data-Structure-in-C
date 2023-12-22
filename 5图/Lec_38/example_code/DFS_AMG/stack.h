#ifndef __DFS_STACK_H__
#define __DFS_STACK_H__

#include <stdio.h>

extern int stack[512];     // 用数组实现栈
extern int top;            // 栈顶指针

void push(int c);
int pop(void);
int isEmpty(void);
int isFull(void);

#endif //!__DFS_STACK_H__