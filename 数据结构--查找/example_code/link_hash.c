#include <stdio.h>
#include <stdlib.h>

#define SIZE 12
#define M 15
#define P 13

// ------ 定义链表结构 -----
struct node
{
    unsigned int elem;
    struct node *next;
};

// -------- 函数声明 ----------
int hash(int key);                                            // 哈希函数
void insert_hashtable(struct node * HT[], int key);           // 插入新节点
void show_hashtable(struct node * HT[], int m);
int search_hashtable(struct node * HT[], int key);

// -------- main ----------
int main(void)
{
    int arr[SIZE] = {14, 36, 42, 38, 40, 15, 19, 12, 51, 65, 34, 25};
    int num, result;

    // 哈希表: 这是一个指针数组, 此时这个数组的每一个元素应该是一个链表节点指针, 指向链表头.
    struct node * HT[M] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}; 

    for(int i = 0; i < SIZE; i++){
        insert_hashtable(HT, arr[i]);
    }

    printf("Show Hash Table:\n");
    show_hashtable(HT, M);

    printf("Please enter a number you want to find:\n");
    scanf("%d", &num);
    result = search_hashtable(HT, num);
    if(result == 1){
        printf("Find %d in link hash table.\n", num);
    }
    else{
        printf("Cannot find %d in link hash table.\n", num);
    }
    return 0;
}

// -------- 函数实现 ------------
void insert_hashtable(struct node * HT[], int key)
{
    int index = hash(key);
    struct node *pt = (struct node *) malloc(sizeof(struct node));   // 开辟节点需要的空间
    pt->elem = key;
    pt->next = HT[index];  // 接入原来的表头

    HT[index] = pt;  // 更新表头
}

int hash(int key)
{
    return key % P;
}

void show_hashtable(struct node * HT[], int m)
{
    struct node * pt;
    for (int i = 0; i < m; i++){
        printf("Hash Table index %d has: ", i);
        // 遍历链表
        for (pt = HT[i]; pt != NULL; pt = pt->next){
            printf("%d ", pt->elem);
        }
        printf("\n");
    }
}

int search_hashtable(struct node * HT[], int key)
{
    int index = hash(key);
    struct node * pt;
    for(pt = HT[index]; pt != NULL; pt = pt->next){
        if(pt->elem == key){
            return 1;
        }
    }
    return 0;
}