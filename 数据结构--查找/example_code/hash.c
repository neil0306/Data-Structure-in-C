#include <stdio.h>
#include <stdlib.h>

#define SIZE 12         // 欲存放的元素个数
#define M 15            // 哈希空间大小
#define P 13            // 不大于M的最大质数

// ------------- 函数声明 -------------
int hash(int key);                              // 哈希函数
int insert_hashtable(int HT[], int key);        // 往哈希表中插入新元素
int line_detect(int HT[], int H0, int key);     // 线性探测法
void show_hashtable(int HT[], int m);           // 显示哈希表内容
int search_hashtable(int HT[], int key);        // 查找元素

// ------------- main ----------------
int main(void)
{
    int arr[SIZE] = {14, 36, 42, 38, 40, 15, 19, 12, 51, 65, 34, 25};
    int HT[M] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};                   // Hash Table
    int num = 0;
    int result;

    for(int i = 0; i < SIZE; i++){
        if (insert_hashtable(HT, arr[i]) != 1){
            printf("Fail to create Hash Table.\n");
            return 0;
        }
    }

    printf("Show Hash Table:\n");
    show_hashtable(HT, M);

    printf("Please enter a number you want to find in Hash Table: ");
    scanf("%d", &num);
    result = search_hashtable(HT, num);
    if(result != -1){
        printf("Find %d in position %d.\n", num, result);
    }
    else{
        printf("Cannot find %d in hash table.\n", num);
    }

    return 0;
}

// ------------ 函数实现 ----------------
int insert_hashtable(int HT[], int key)
{
    int index = hash(key);
    int Hi;

    if(HT[index] == -1){        // 无冲突
        HT[index] = key;
        return 1;
    }
    else{                       // 有冲突
        Hi = line_detect(HT, index, key);       // 使用线性探测法中的插入新元素分支
        if(-1 != Hi){
            HT[Hi] = key;
            return 1;
        }
    }
    return 0;
}

int hash(int key)
{
    return key % 13;
}

int line_detect(int HT[], int H0, int key)
{
    int Hi;
    for (int offset = 1; offset <= M; offset++){
        Hi = (H0 + offset) % M;
        if(HT[Hi] == -1){           // 这个分支用来寻找不冲突的位置 ==> 用于插入新元素
            return Hi;
        }
        else if(HT[Hi] == key){     // 这个分支用来寻找key的位置 ==> 用于查找元素
            return Hi;
        }
    }
    return -1;                      // 由于哈希填充因子的存在, 创建的哈希空间总是要多一些的, 所以返回-1的情况几乎不会发生.
}

void show_hashtable(int HT[], int m)
{
    for(int i = 0; i < M; i++){
        printf("%d\t", HT[i]);
    }
    printf("\n");
}

int search_hashtable(int HT[], int key)
{
    int Hi = -1;                // 存放找到的元素位置
    int H0 = hash(key);

    if(-1 == HT[H0]){           // 不存在这个值
        return -1;
    }
    else if(HT[H0] == key){     // 无冲突
        return H0;
    }
    else{                       // 出现过冲突
        Hi = line_detect(HT, H0, key);       // 使用线性探测法中的查找分支
        if(HT[Hi] == key){
            return Hi;
        }
        else{
            return -1;
        }
    }
}