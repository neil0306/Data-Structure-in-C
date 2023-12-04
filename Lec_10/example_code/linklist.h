#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>

struct node
{
    unsigned char elem;
    struct node * next;     // 下一个节点的指针类型是 "struct node"
};

void create_linklist(unsigned char elem);
void insert_node(int pos, char elem);
void delete_node(int pos);
void print_linklist();
int search(unsigned char elem);

#endif