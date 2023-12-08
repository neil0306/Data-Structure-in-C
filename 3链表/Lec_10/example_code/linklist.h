#ifndef __LOOP_LINKLIST_H__
#define __LOOP_LINKLIST_H__

#include <stdio.h>

struct node
{
    int elem;
    struct node * next;     // 下一个节点的指针类型是 "struct node"
};

void create_linklist(int elem);
void insert_node(int pos, char elem);
void delete_node(int pos);
void print_linklist();
int search(int elem);

#endif //! __LOOP_LINKLIST_H__
