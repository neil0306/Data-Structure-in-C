#ifndef __DUL_LINKLIST_H__
#define __DUL_LINKLIST_H__

#include <stdio.h>

extern struct node * head;      // 声明外部变量 head, 它是在 linklist.c 里定义的
extern struct node * tail;      // 声明外部变量 tail, 它是在 linklist.c 里定义的

struct node
{
    int elem;
    struct node * next;     // 下一个节点的指针类型是 "struct node"
    struct node * pre;      // 双向链表: 多一个前趋点指针
};

void create_linklist(int elem);
void insert_node(int pos, int elem);
void delete_node(int pos);
void print_linklist(struct node *linklist_head);
int search(int elem);                       // 查找链表中第一个数据为 elem 的节点
void reverse_print_linklist();

#endif