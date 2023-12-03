#include "linklist.h"
#include <stdlib.h>

struct node *head = NULL;
struct node *tail = NULL;           // 由于使用了尾插法, 这里定义一个 尾指针

// 链表基本操作--创建链表
void create_linklist(unsigned char elem)
{
    /*
        创建一个链表分为两步:
            1. 创建节点:
                1) 开辟一段内存空间作为新节点, 并划分出数据域以及指针域, 然后返回当前内存空间的起始地址;
                2) 填充数据域, 指针域设置为 NULL
            2. 将节点接入链表
                - 可简单分为 头插法 和 尾插法.
                    - 对于 尾插法: 除了head不动之外, 需要定义一个 tail 指针, 它永远指向最后一个节点
                        1) 先检查头指针, 将某个指针指向新增节点(以下情况只会发生一种, 用if-else): 
                            - 如果新增的节点是链表的第一个节点, 则直接让 head 指向加入的加点; 
                            - 如果新增的节点不是链表的第一个节点, 则先将尾节点的next指针指向新增节点.
                        2) 更新尾结点: 由于是尾插法, 新加入的节点一定是链表最末尾的节点, 故尾结点**最终**一定指向新加入的节点.

    */
    
    // 1. 创建节点
    struct node *p = (struct node *)malloc(sizeof(struct node));     // malloc 返回的类型是 (void *), 所以需要强制类型转换
    p->elem = elem;     // 节点的数据域赋值
    p->next = NULL;     // 节点的指针域先初始化为 NULL, 因为还没有开始连接进链表中

    // 2. 将新建的节点接入链表中, 让原 链表的某个指针 指向新增节点(这里使用尾插法)
    if (head == NULL){      // 先检查头指针
        head = p;           // 尾插法: 如果链表还没有任何节点, 则将当前节点作为第一个节点 ==> head 指针指向新增节点
    }
    else{
        tail->next = p;     // 尾插法: 如果链表已经有节点, 则将当前的尾结点的 next 指针指向新增节点
    }

    tail = p;               // 更新 tail 指针指向的节点: 将新增的 p 节点成为新的尾结点, 故 tail 指针移动到 p 的起始地址.
}

void insert_node(int pos, char elem)    // pos 为插入的位置, elem 为插入节点的元素
{
    /*
        在指定位置插入新节点:
            1. 遍历链表
                找到 pos 的前一个节点(前驱点)
                    建立一个 pre指针 指向前驱点节点
    */

    struct node * pre = head;   // 从head开始遍历, 所以pre初始化为 head
    int i = 0;
    struct node * p = (struct node *) malloc(sizeof(struct node));

    // 遍历链表, 使用 pre 作为 "前驱点"
    while(i < pos -1){
        pre = pre->next;
        i++;
    }

    // 新开辟一个新节点, 并赋值
    p->elem = elem;
    p->next = pre->next;        // pre->next 就是 pos 位置的节点
    pre->next = p;

} 