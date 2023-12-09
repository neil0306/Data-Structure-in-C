#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include "binary_tree.h"    // 为了使用二叉树结构体

#define SIZE 512

struct BinTree_node queue[SIZE];

void enqueue(struct BinTree_node c);
struct BinTree_node dequeue(void);
int isEmpty();
int isFull();

#endif //! __QUEUE_H__