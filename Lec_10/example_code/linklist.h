#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>

struct node
{
    unsigned char elem;
    struct node * next;     // 下一个节点的指针类型是 "struct node"
};



#endif //!__LINKLIST_H__