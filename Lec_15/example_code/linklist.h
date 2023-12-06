#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>

extern struct node * head;      // 声明外部变量 head, 它是在 linklist.c 里定义的
extern struct node * tail;      // 声明外部变量 tail, 它是在 linklist.c 里定义的

struct node
{
    int elem;
    struct node * next;     // 下一个节点的指针类型是 "struct node"
};

void create_linklist(int elem);
void insert_node(int pos, int elem);
void delete_node(int pos);
void print_linklist(struct node * linklist_head);
int search(int elem);                       // 查找链表中第一个数据为 elem 的节点
void delete_repeat(struct node * head);     // 删除重复节点
int find_mid(struct node * head);           // 查找中间节点的元素
int find_last_nth(struct node * head, int n);                       // 查找倒数第 n 个节点

#endif