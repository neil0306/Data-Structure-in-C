#ifndef __CPP_VERSION_DUL_LINKLIST_H__
#define __CPP_VERSION_DUL_LINKLIST_H__

#include <iostream>
#include <string>

using namespace std;

template <class T>
class linklist
{
    public:
    // 节点结构体
    struct node
    {
        T elem;
        struct node *next;
        struct node *pre;       // 双向链表需要增加一个 pre指针, 指向前一个节点
    };

    public:
        struct node * head;
        struct node * tail;
        int len;

    public:
        void create_linklist(T elem);
        void insert_node(int pos, T elem);
        void delete_node(int pos);
        void print_linklist();
        bool search(T elem);
        void reverse_print();

    public:
        linklist() : head(nullptr), tail(nullptr), len(0){}
        ~linklist()
        {
            // 从头结点开始删
            struct node * pre = head;      // 待删除节点 的 前一个节点

            if( pre == nullptr || nullptr == pre->next){
                // 空链表
                return;
            }
            else{
                for(int i = 0; i < len; i++){
                    pre = head;        // 从头结点开始删
                    head = head->next;
                    delete pre;
                }
            }
            len = 0;
        }
};

template <class T>
void linklist<T>::create_linklist(T elem)
{
    struct node *p = new struct node;
    p->elem = elem;
    p->next = nullptr;
    p->pre = nullptr;
    
    if(head == nullptr){
        head = p;
    }
    else{
        tail->next = p;
        p->pre = tail;
        p->next = nullptr;
    }

    tail = p;
    len++;
}

template<class T>
void linklist<T>::insert_node(int pos, T elem)
{
    struct node *p = new struct node;       // 新增节点指针
    struct node * pre;
    
    // 如果在头结点位置新增: 无需使用 pre, 直接插入新节点即可.
    if(0 == pos){
        // 完善新节点
        p->elem = elem;
        p->next = head;
        head->pre = p;      // 双向节点, 原来的头结点的pre指针需要指向新增节点
        p->pre = nullptr;
        head = p;           // 确认指向新节点的指针
    }
    else{
        pre = head;
        for (int i  = 0; i < pos -1; i++){     // 移动 pre指针 到 pos 的前一个节点
            pre = pre->next;
        }

        // 完善新节点 & 确认指向新节点的指针
        p->elem = elem;
        p->pre = pre;                       // 双向链表别忘了处理pre指针
        p->next = pre->next;
        if(pre->next != nullptr){           // 双向链表, 如果在尾部增加, 需要确认有没有pre指针
            pre->next->pre = p;
        }
        pre->next = p;

        if (p->next == nullptr){            // 如果在尾部插入节点, 则更新尾指针位置
            tail = p;
        }
    }
    len += 1;
}

template <class T>
void linklist<T>::delete_node(int pos){
    struct node * p;        // 待删除节点
    struct node * pre;      // 待删除节点 的 前一个节点

    if (len != 0){
        if (0 == pos){          // 如果删除的是头节点
            pre = head;
            head = head->next;
            head->pre = nullptr;
            delete(pre);
        }
        else{
            // 遍历链表, 找到pos的前一个节点
            pre = head;
            for (int i = 0; i < pos -1 ; i++){      // 从0开始计数, 循环停止时, pre位于 pos - 1
                pre = pre->next;
            }
            p = pre->next;
            
            pre->next = p->next;        // 从链表中断开待删除节点

            // 检查删除的是否为尾结点
            if (p->next != nullptr){
                p->next->pre = pre;
            }
            else{
                tail = pre;
            }
            
            // 释放内存
            delete p;
        }
        len--;
    }
    else{
        cout << "There is nothing to delete!" << endl;
    }
}

template<class T>
void linklist<T>::print_linklist()
{
    struct node *p;         // 遍历过程中滑动的节点指针
    for (p = head; p != nullptr; p = p->next){
        cout << p->elem << " ";
    }
    cout << endl;
}

template<class T>
bool linklist<T>::search(T elem)
{
    struct node *p = head;
    for (p = head; p != nullptr; p = p->next){
        if(p->elem == elem){
            return true;
        }
    }
    return false;
}

template<class T>
void linklist<T>::reverse_print()
{
    node * p;
    for (p = tail; p != nullptr; p = p->pre){
        cout << p->elem << " ";
    }
    cout << endl;
}
#endif //!__CPP_VERSION_DUL_LINKLIST_H__
