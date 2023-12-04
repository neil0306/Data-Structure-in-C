#include "linklist.h"
#include <stdio.h>

int main(void)
{
    // C语言是面向过程的语言, 它不像C++有对象的概念, 此时要区分多个链表, 就只能创建多个链表头
    struct node * head1 = NULL;
    struct node * head2 = NULL;
    struct node * p = NULL;     // 比较节点内容时, 对应 head1 上的链表的节点
    struct node * q = NULL;     // 比较节点内容时, 对应 head2 上的链表的节点

    // 创建链表1: 这里实际使用的是 head 来创建的(主要是因为函数里写死了...)
    create_linklist(1);
    create_linklist(9);
    create_linklist(13);
    create_linklist(27);
    head1 = head;           // 将 head 的地址复制给 head1, 完成 链表1 的创建 
    print_linklist(head1);

    // 创建链表2: 这里实际使用的是 head 来创建的(主要是因为函数里写死了...)
    head = NULL;            // 重置 head
    create_linklist(3);
    create_linklist(5);
    create_linklist(14);
    create_linklist(81);
    create_linklist(88);
    create_linklist(95);
    create_linklist(99);
    head2 = head;           // 将 head 的地址复制给 head2, 完成 链表2 的创建 
    print_linklist(head2);

    // 再次使用head, 把head对应的链表作为排序后的链表
    head = NULL;        // 重置链表, 作为结果链表
    p = head1;          // 链表1的节点
    q = head2;          // 链表2的节点

    // 开始比较 & 合并节点
    while (p != NULL && q != NULL){            // 比较的终止条件是: 其中一个链表遍历到最后一个节点. 两个节点指针都不是NULL时, 继续比较
        if (p->elem <= q->elem){
            if (head == NULL){          // case: 对于结果链表的 **头结点** 位置
                head = p;               // 更新第一个节点
            }
            else{                       // case: 对于结果链表的 **非头结点** 位置
                tail->next = p;
            }

            tail = p;           // 更新尾指针
            p = p->next;        // 移动到下一个节点, 继续比较
        }
        else{
            if(head == NULL){           // case: 对于结果链表的 **头结点** 位置
                head = q;
            }
            else{                       // case: 对于结果链表的 **非头结点** 位置
                tail->next = q;
            }

            tail = q;           // 更新尾指针
            q = q->next;        // 移动到下一个节点, 继续比较
        }
    }
    
    tail->next = p?p:q;  // 拼接较长的链表的剩余节点, 等同于 tail->next = p == NULL? p : q;      

    print_linklist(head);
    return 0;
}
