#include "linklist.h"
#include <stdlib.h>

struct node *head = NULL;
struct node *tail = NULL;           // 由于使用了尾插法, 这里定义一个 尾指针

// 链表基本操作--创建链表
void create_linklist(int elem)
{
    /*
        创建一个链表分为两步:
            1. 创建节点:
                1) 开辟一段内存空间作为新节点, 并划分出数据域以及指针域, 然后返回当前内存空间的起始地址;
                2) 填充数据域, 指针域设置为 NULL
            2. 将节点接入链表
                - 可简单分为 头插法 和 尾插法.
                    - 对于 尾插法: 除了head固定指向链表第一个节点之外, 需要定义一个 tail 指针, 让它永远指向最后一个节点
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

void insert_node(int pos, int elem)    // pos 为插入新节点的位置, elem 为待插入节点的数据域所存放的值
{
    /*
    在指定位置插入新节点:
        如果插入的位置**是头结点**:
            1. 直接将新增节点的 next指针 指向 head 所指向的位置 ==> 效果就是 新增节点 位于链表的头部
            2. 将head指向的位置改为 新增节点 ==> 坐实新增节点的地位
        如果插入的位置**不是头结点**
            1. 遍历链表找到 pos位置 的前一个节点(前趋点)
                建立一个 pre指针 指向前趋点节点
            2. 将 pre指针 指向新增节点, 然后将 新增节点 的 next指针 指向原来pos位置的节点.
                - 为了防止 指向pos位置的节点指针丢失, 需要先将这个指针先存入 "新插入节点的指针域(将它的next设置为指向原来pos位置的节点)" 
                - 然后再将pre的 next指针 指向新增节点
            3. (不能忘记!!!!) 检查插入位置是否为末尾位置 ==> 坐实新增节点的地位
    */

    struct node * p = (struct node *) malloc(sizeof(struct node));      // 为准备插入的节点开辟空间
    struct node * pre = head;   // 从 head 开始遍历, 所以pre初始化为 head
    int i = 0;
    if (0 == pos){
        p->next = head;
        p->elem = elem;
        head = p;
    }
    else{
        // 遍历链表, 使用 pre 作为 "前趋点"
        while(i < pos -1){      // 解析: 遍历的节点序号从0开始, 如果要找 index 为5对应的pre位置, 则需要走4次循环; 要找 6对应的pre位置, 就需要走5次循环, 因此这里条件为 pos - 1
            pre = pre->next;
            i++;
        }

        // 新开辟一个新节点, 并赋值
        p->elem = elem;
        p->next = pre->next;        // 一定要先将插入节点的next指针指向pos位置的节点, 否则指向pos位置的指针会丢失! (pre->next 就是 pos 位置的节点)
        pre->next = p;              // 将pre的next指针指向新插入的节点

        // 检查插入的节点是否为尾节点, 如果是, 则需要更新 tail指针, 坐实新增节点在链表的地位
        if (p->next == NULL){        // 假如 pre 刚好是末尾节点, 则新插入的节点的 next指针 就会恰好为 NULL
            tail = p;
        }
    }
} 

void delete_node(int pos)
{
    /*
    删除节点:
        与 "插入节点" 一样, 删除节点也需要 "前趋点" pre.
        如果删除的**是头结点**
            1. 把 pre 设置为 head 
            2. 将 head 存放的地址更新为 原来head的指针域里存放的地址 (head直接挪到下一个位置)
            3. 释放被删除的节点空间, 防止内存泄露
        如果删除的**不是头结点**
            1. 遍历链表, 找到前趋点(index 为 pos - 1 的位置)
            2. 将准备删除的节点指针 p 赋值为 pre->next (也就是 p 指向了 pos 位置)
            3. 将 pre指针 指向 pos 的下一个节点 (此时链表将绕开 pos 节点)
            4. 检查 pos 指向的节点是否为 "尾结点", 特征是 p->next 为 NULL
            5. 释放被删除的节点空间, 防止内存泄露
    */
    struct node * pre = head;       // 用于遍历链表, 找到 index 为 pos - 1 的位置 (前趋点), 遍历时从第一个节点开始, 故初始化为 head
    struct node * p;                // 指向待删除节点的指针
    int i;

    if(0 == pos){                   // 删除的是头结点
        pre = head;                 // 虽然前面定义 pre 的时候已经把 head 里面存放的 **地址拷贝到 pre**, 但是为了思路清晰, 这里也可以再写一次.
        head = head->next;          // head 里存放的地址直接替换为下一个节点的起始地址 (注意此时并不会影响到 pre)
        free(pre);                  // pre 初始化的时候已经是head
    }
    else{
        // 遍历链表, 找到 pos 的前一个节点(前趋点), 跳出循环时, i 的位置就是前趋点的位置
        while(i < pos - 1){
            pre = pre->next;
            i++;
        }
        p = pre->next;                  // 确定待删除节点

        // 更新 pre节点的 next指针 
        pre->next = p->next;            // 将 pre指针 指向 pos 的下一个节点

        // 检查删除的是不是尾结点
        if(p->next == NULL){            // 如果删除的是尾结点
            tail = pre;                 // 坐实 当前删除的节点是尾结点, 此时 尾结点 就变成前一个节点.
        }

        // 释放被删除的节点, 防止内存泄露
        free(p);                        // 释放被删除的节点
    }
}

void print_linklist(struct node * linklist_head)
{
    // 遍历并打印节点内容, 注意只能从 head 开始遍历
    struct node * p;
    for (p = linklist_head; p != NULL; p = p->next){
        printf("%d ", p->elem);
    }
    printf("\n"); 
}

int search(int elem)
{
    struct node *p;
    for (p = head; p != NULL; p = p->next){
        if (p->elem == elem){
            return 1;
        }
    }
    return 0;
}

void delete_repeat(struct node * head)
{
    int flag[10] = {0};
    struct node *p = head;      // p 指向当前遍历的节点的 "前一个节点" (前趋点)

    // 第一个节点必不可能重复, 可以直接赋值为1
    flag[p->elem] = 1;

    while(p->next != NULL){     // 从链表的第二个节点开始循环遍历
        if (flag[p->next->elem] == 0){
            flag[p->next->elem] = 1;      // p->next 才是当前遍历的节点, p是前趋点
            p = p->next;
        }
        else{                   // 处理重复节点
            struct node * q = p->next;    // 存一份 当前节点 的内存地址, 用来释放内存
            p->next = q->next;            // 绕开 当前节点
            free(q);
        }
    }
}

int find_mid(struct node * head)
{
    // 快慢指针法
    struct node * p = head;        // 快指针
    struct node * q = head;        // 慢指针

    while(p != NULL && p->next != NULL){
        p = p->next->next;      // 快指针: 每次走2个节点
        q = q->next;            // 慢指针: 每次走1个节点
    }
    return q->elem;
}

int find_last_nth(struct node *head, int n)
{
    struct node * p = head;  // 快指针
    struct node * q = head;  // 慢指针
    int i;
    for (i = 0; i < n -1; i++ )
    {
        p = p->next;
    }

    while (p->next != NULL){    // 快指针走到末尾时, 就找到了倒数第 n 个节点
        p = p->next;
        q = q->next;
    }

    return q->elem;             // 慢指针就是倒数第 n 个节点
}