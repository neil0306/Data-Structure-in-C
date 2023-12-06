#ifndef __CPP_VERSION_LOOP_LINKLIST_H__
#define __CPP_VERSION_LOOP_LINKLIST_H__

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
            do{
                tail->next = head->next;
                p = head;
                head = head->next;
                // cout << "deleting: " << p->elem << endl;
                delete(p);
                len--;
            }while(head->next != tail);
            delete head;    // 别忘了还有个头节点没删(其实剩下的那个也是尾节点)
            len --;
            delete tail;
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
    tail->next = head;        // 循环链表
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
        tail->next = head;
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

        if (p->next == head){           // 循环链表: 尾结点的next指针存放着head的地址
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
            // cout << "delete element: " << pre->elem << endl;
            delete(pre);

            tail->next = head;  // 循环链表, 动过 head 就要更新 tail
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
            if (p->next == head){       // 循环链表: 尾结点的next指针存放着head的地址
                tail = pre;
            }
            
            // 释放内存
            cout << "deleting element: " << p->elem << endl;
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
    p = head;
    do{
        cout << p->elem << " ";
        p = p->next;
    }while(p != head);
    cout << endl;
}

template<class T>
bool linklist<T>::search(T elem)
{
    struct node *p = head;

    do{
        if(p->elem == elem){
            return true;
        }
        p = p->next;
    }while(p != head);

    // for (p = head; p != nullptr; p = p->next){
    //     if(p->elem == elem){
    //         return true;
    //     }
    // }
    return false;
}

#endif //!__CPP_VERSION_LOOP_LINKLIST_H__
