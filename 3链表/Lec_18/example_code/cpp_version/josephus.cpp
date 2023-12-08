#include "loop_linklist_cpp.h"
#include <iostream>

using namespace std;

int main(void)
{
    int n, k, m;
    linklist<int> list1;
    linklist<int>::node *p;   // 用来指向用户指定要删除的节点 (每次更新链表后, 编号为k的节点)
    linklist<int>::node *q;   // 用来指向用户指定要删除的节点 的 前一个节点

    // 创建循环链表
    cout << "please enter the number of person: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        list1.create_linklist(i);
    }
    list1.print_linklist();

    // 获取用户指定的编号为 k 的节点  (每次更新链表后, 编号为k的节点)
    cout << "please enter the start number: ";
    cin >> k;
    p = list1.head;
    while(--k){     // 跳出循环时, p指向当前链表 编号为k 的节点 (注意从1开始计数)
        p = p->next;
    }
    // cout << p->elem << endl;

    // 按照约瑟夫环规则, 依次删除节点
    cout << "please enter the m: ";
    cin >> m;
    if(1 == m){   // case: k = 1, 此时无前趋点, 此时直接依次删除即可
        for (int i = 0; i < n; i++){
            cout.width(3);
            cout << p->elem;
            p = p->next;
        }
        printf("\n");
    }
    else{        // case: k > 1
        while(n--){     // n 也表示链表长度

            // 因为要操作(删除/增加)某个节点时, 我们总是需要用到它的前一个节点, 故先找到这个节点
            // 根据约瑟夫环的规则, 要从 编号为k 的节点开始数
            for (int i = 1; i < m - 1; i++){        // 通过总结规律, 不难发现, 要找到 m-1 这个节点需要循环 m-2 次, 故这里 i < m-1 
                p = p->next;
            }
            q = p;                  // 前趋点初始化
            p = p->next;            // p移动到即将被删除的节点

            cout << p->elem << " ";

            q->next = p->next;      // 绕开即将删除的节点

            delete p;               // 释放被删除的节点
            list1.len--;

            p = q->next;            // p 指向删除节点后的下一个位置 (约瑟夫环在下一次删除节点时, 开始遍历的位置)
        }
        cout << endl;
    }
    return 0;
}