#ifndef __CPP_VERSION_LINKLIST_H__
#define __CPP_VERSION_LINKLIST_H__

#include <iostream>

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

    public:
        linklist() : head(NULL), tail(NULL), len(0){}
        ~linklist()
        {
            struct node * p;
            // 直接从头节点开始删
            while(head->next != nullptr){
                p = head->next;
                head->next = p->next;       // 注意是谁的指针赋给谁, 不能搞混
                delete(p);
                len--;
            }
            delete head;    // 别忘了还有个头节点没删(其实剩下的那个也是尾节点)
            len --;
            // cout << "There are " << len << " nodes left in your linklist." << endl;
            // cout << "Finish deconstruction!" << endl;
        }
};

template <class T>
void linklist<T>::create_linklist(T elem)
{
    struct node *p = new struct node;
    p->elem = elem;
    p->next = NULL;
    
    if(head == nullptr){
        head = p;
    }
    else{
        tail->next = p;
    }

    tail = p;
    len += 1;
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

        // 确认指向新节点的指针
        head = p;
    }
    else{
        pre = head;
        for (int i  = 0; i < pos -1; i++){     // 移动 pre指针 到 pos 的前一个节点
            pre = pre->next;
        }

        // 完善新节点 & 确认指向新节点的指针
        p->elem = elem;
        p->next = pre->next;
        pre->next = p;

        if (nullptr == p->next){
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
            cout << "delete element: " << pre->elem << endl;
            delete(pre);
        }
        else{
            // 遍历链表, 找到pos的前一个节点
            for (int i = 0; i < pos -1; i++){
                pre = pre->next;
                i++;
            }
            p = pre->next;

            pre->next = p->next;        // 从链表中断开待删除节点

            // 检查删除的是否为尾结点
            if (p->next == nullptr){
                tail = pre;
            }
            
            // 释放内存
            delete p;
        }
        len -= 1;
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
    struct node *p;
    for (p = head; p != nullptr; p = p->next){
        if(p->elem == elem){
            return true;
        }
    }
    return false;
}

#endif //!__CPP_VERSION_LINKLIST_H__