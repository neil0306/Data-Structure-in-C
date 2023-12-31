#include <stdio.h>
#include <stdlib.h>

#define SIZE 16     // 假定待排序数字一共16个
#define M 10        // 假定一共划分成10个桶

struct node
{
    unsigned int elem;
    struct node * next;
};

void RadixSort(int array[], int n);
int Search_Maxbit(int array[], int n);
int Bitnumber(int x, int bit);
void Show_Bucket(struct node * Bucket[], int m);

int main(void)
{
    int scores[SIZE] = {66, 73, 51, 71, 85, 46, 82, 12, 73, 92, 79, 5, 70, 81, 88, 100};

    printf("Original array\t: ");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", scores[i]);
    }
    printf("\n");

    RadixSort(scores, SIZE);

    printf("After sort\t: ");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", scores[i]);
    }
    printf("\n");
    return 0;
}

void RadixSort(int array[], int n)
{
    int maxbit;

    // 找出待排序数据的最大数值, 确定有多少位
    maxbit = Search_Maxbit(array, n);

    for (int k = 1; k <= maxbit; k++){
        struct node * Bucket[M] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

        for(int i = 0; i < n; i++){
            int index = Bitnumber(array[i], k);      // 1:个位  2:十位  3:百位
            struct node * p = (struct node *)malloc(sizeof(struct node));

            p->elem = array[i];
            if(Bucket[index] == NULL){      // 空桶, 放在头
                Bucket[index] = p;
                p->next = NULL;
            }
            else{                           // 非空桶, 放末尾
                struct node *point = Bucket[index];
                struct node *pre = NULL;

                // 找尾结点
                while(point != NULL){
                    pre = point;
                    point = point->next;
                }

                // 插入尾部
                pre->next = p;
                p->next = point;        // point 此时其实就是NULL
            }
        }
        // Show_Bucket(Bucket, M);

        // 元素依次放回桶里
        for (int i = 0, j = 0; i < M; i++){
            struct node * point = Bucket[i];
            if(point == NULL){                // 空桶
                continue;
            }
            
            // 非空桶, 元素放回原数组
            while(point != NULL){ 
                array[j] = point->elem;
                point = point->next;
                j++;
            }
            
        }
        // Show_Bucket(Bucket, M);
    }
}

// 计算待排序数组一共有多少位
int Search_Maxbit(int array[], int n)
{
    int max = array[0];
    int digits = 0;

    // 找最大值
    for (int i = 1; i < n; i++){
        if(array[i] > max){
            max = array[i];
        }
    }

    // 确认有多少位
    while(max != 0){
        digits++;
        max /= 10;
    }

    return digits;
}

// 计算当前待插入元素的 第bit位 是多少
int Bitnumber(int x, int bit)
{
    int temp = 1;
    for(int i = 1; i < bit; i++){
        temp *= 10;
    }
    return (x / temp) % 10;
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