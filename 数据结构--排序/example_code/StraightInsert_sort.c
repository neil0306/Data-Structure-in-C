#include <stdio.h>
#define SIZE 10 
#define MAX 100

void StraightInsertSort(int array[], int n);


int main(void)
{
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};

    printf("Original array: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    int sort[MAX +1];       // sort数组是一个辅助数组, 用来做中间排序的转换, 插入排序中需要预留多一个位置用来交换元素, 故+1
    // 拷贝数组
    for(int i = 0; i < SIZE; i++){
        sort[i+1] = arr[i];
    }

    // 执行排序
    StraightInsertSort(sort, SIZE);

    // 把排序结果放回原数组
    for(int i = 0; i < SIZE; i++){
        arr[i] = sort[i+1];
    }

    printf("After sort: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void StraightInsertSort(int array[], int n)
{
    // 从 sort[2] 开始进行遍历, 与前面的所有元素进行比较, 由于数组是连续存放的, 故插入元素时需要挪动后面的所有元素
    int i, j;
    for (i = 2; i <= n; i++){        // array 的 0位置 预留出来用于暂存插入元素, 故 i<=n
        if (array[i] < array[i-1]){     // 如果 当前遍历的元素i 比前一个元素小, 则将 array[i] 放入 array[0], 并将 i-1元素 往后移动一位
            array[0] = array[i];
            array[i] = array[i-1];

            // 依次判断前面已排序好的元素(如果存在)是否需要往后挪动
            for(j = i - 2; array[j] > array[0]; j--){    // 注意是往数组的开头方向遍历, 故j--
                array[j+1] = array[j];  // 把元素j数组末尾方向移动一位
            }

            // 已经找到正确的插入位置, 将待插入元素丢进去即可
            array[j+1] = array[0];
        }
    }
}