#include <stdio.h>
#include <stdlib.h>

#define SIZE 15     // 假定待排序数字一共15个
#define M 11        // 假定一共划分成11个桶

struct node
{
    unsigned int elem;
    struct node * next;
};

void BucketSort(int array[], int n);
void InsertBucket(struct node * Bucket[], unsigned int value);
int ScoreSort(unsigned int value);
void Show_Bucket(struct node * Bucket[], int m);


int main(void)
{
    int scores[SIZE] = {66, 73, 51, 71, 85, 46, 82, 12, 73, 92, 79, 5, 70, 81, 88};

    printf("Original array\t: ");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", scores[i]);
    }
    printf("\n");

    BucketSort(scores, SIZE);

    printf("After sort\t: ");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", scores[i]);
    }
    printf("\n");
    return 0;
}

void BucketSort(int array[], int n)
{
    struct node * Bucket[M] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    // step1: 划分区间, 将元素放入区间(放入的过程中完成桶内排序)
    for (int i = 0; i < n; i++){
        InsertBucket(Bucket, array[i]);   // 往桶里放值 (链表中插入节点)
    }

    // Show_Bucket(Bucket, M);              // 打印一下桶里的内容

    // step2: 按照桶的顺序, 重新放回原数组
    for (int i = 0, j = 0; i < M; i++){
        struct node * point = Bucket[i];
        if(point == NULL){                // 空桶
            continue;
        }
        else{
            // 非空桶, 元素放回原数组
            while(point != NULL){ 
                array[j++] = point->elem;
                point = point->next;
            }
        }
    }
}

void InsertBucket(struct node * Bucket[], unsigned int value)
{
    int index; 
    struct node * p = (struct node *)malloc(sizeof(struct node));   // 创建新节点

    p->elem = value;
    index = ScoreSort(value);          // 计算插入值将要放入的桶的序号 (含义上等同于哈希函数)
    
    /*
        开始往桶里放元素, 放的时候就要把排序的工作完成.
    
            case1: 
                如果桶里现在一个节点都没有, 或者已经有头节点, 但新来的节点p 比该头节点 小
                    ==> 直接将新节点插入链表头   (链表头存放的是当前链表的最小值)
                
            case2:
                如果链表已经有节点, 且新来的节点 p 大于 链表头结点
                    ==> 找到比p大, 
    */ 
    if(Bucket[index] == NULL || Bucket[index]->elem > p->elem){
        p->next = Bucket[index];
        Bucket[index] = p;
    }
    else{                                                       // 通内有链表, 且新来的节点要大于链表头
        struct node * pre = NULL;                               // 前趋点
        struct node * point = Bucket[index];                    // 后继点  (满足 point->elem > p->elem 的第一个节点)

        // 找前趋点和后继点
        while(point != NULL && point->elem < p->elem){
            pre = point;
            point = point->next;
        }

        // 插入新节点
        pre->next = p;
        p->next = point;
    }
}

int ScoreSort(unsigned int value)
{
    return value / 10;
}

void Show_Bucket(struct node * Bucket[], int m)
{
    struct node *p;
    for (int i = 0; i < m; i++){
        printf("Bucket index %d has: ", i);
        for(p = Bucket[i]; p != NULL; p = p->next){
            printf("%d ", p->elem);
        }
        printf("\n");
    }
}
