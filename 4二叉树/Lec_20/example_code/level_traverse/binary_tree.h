#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>
#include <stdlib.h>

// 结构体 -- 二叉树节点
struct BinTree_node
{
    unsigned char elem;
    struct BinTree_node *ltree, *rtree;
};

#include "queue.h"      // 为了使用 enqueue(struct BinTree_node)

// 函数声明
struct BinTree_node * create_bintree();         // 创建二叉树
void pre_order(struct BinTree_node * tree);     // 前序遍历
void in_order(struct BinTree_node * tree);      // 中序遍历
void pos_order(struct BinTree_node * tree);     // 后序遍历
void level_traverse(struct BinTree_node * tree);    // 层次遍历

#endif //!__BINARY_TREE_H__