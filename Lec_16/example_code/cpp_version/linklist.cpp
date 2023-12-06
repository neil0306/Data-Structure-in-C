#include <string>
#include "linklist_cpp.h"

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

template<class T>
void linklist<T>::delete_repeat()
{
    struct node * p = head;         // 指向当前遍历节点的"前一个节点"
    struct node * q = nullptr;      // 指向当前遍历的节点
    int flag[10] = {0};

    flag[p->elem] = 0;              // 第一个节点永远不会重复, 直接把数组元素置为一
    while(p->next != nullptr){      // 从第二个节点开始循环
        if(flag[p->next->elem] == 0){
            flag[p->next->elem] = 1;
            p = p->next;
        }
        else{
            q = p->next;             // 备份当前遍历的节点地址, 后面要释放内存
            p->next = q->next;       // 绕开当前节点(因为已经重复出现)
            delete q;
        }
    }
}

template <class T>
int linklist<T>::find_mid()
{
    struct node * p = head;
    struct node * q = head;
    while( p != nullptr  && p->next != nullptr){
        p = p->next->next;
        q = q->next;
    }
    return q->elem;
}

template<class T>
int linklist<T>::find_last_nth(int n)
{
    node * p = head;
    node * q = head;
    for (int i = 0; i < n -1; i++){
        p = p->next;
    }

    while(p->next != nullptr){
        p = p->next;
        q = q->next;
    }

    return q->elem;
}
