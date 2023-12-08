#include <string>
#include "linklist_cpp.h"

int main(void)
{
    linklist<int> list1;
    list1.create_linklist(1);
    list1.create_linklist(9);
    list1.create_linklist(13);
    list1.create_linklist(27);
    list1.print_linklist();
    cout << "-------------" << endl;

    linklist<int> list2;
    list2.create_linklist(3);
    list2.create_linklist(5);
    list2.create_linklist(14);
    list2.create_linklist(81);
    list2.create_linklist(88);
    list2.create_linklist(95);
    list2.create_linklist(99);
    list2.print_linklist();
    cout << "-------------" << endl;

    linklist<int> res;  // 为了防止出现对同一个节点的多次析构, 一定要新建节点
    linklist<int>::node * p = list1.head;
    linklist<int>::node * q = list2.head;

    while(p != nullptr && q != nullptr){
        if(p->elem <= q->elem){          
            res.create_linklist(p->elem);
            p = p->next;
        }
        else{
            res.create_linklist(q->elem);
            q = q->next;
        }
    }
    linklist<int>::node * temp = p == nullptr ? q : p;
    while(temp != nullptr){
        res.create_linklist(temp->elem);
        temp = temp->next;
    }
    res.print_linklist();
    return 0;
}