#include <stdio.h>
#define SIZE 10 
#define MAX 100

void ShellSort(int array[], int n);
void StraightInsert_Sort(int array[], int n);
void ShellInsertSort(int array[], int n, int inc);

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
    ShellSort(sort, SIZE);

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

// 直接插入排序: 这个函数只能以1为增量, 即直接对整个数组进行排序
void StraightInsert_Sort(int array[], int n)
{
    // 从 array[2] 开始进行遍历, 与前面的所有元素进行比较, 由于数组是连续存放的, 故插入元素时需要挪动后面的所有元素
    int i, j;
    for (i = 2; i <= n; i++){           // i = 2, 本质上就是 (1+增量), 由于这里增量为1, 故i从2开始; array 的 0位置 预留出来用于暂存插入元素, 故 i<=n
        if (array[i] < array[i-1]){     // 如果 当前遍历的元素i 比前一个元素小, 则将 array[i] 放入 array[0], 并将 i-1元素 往后移动一位
            array[0] = array[i];
            array[i] = array[i-1];

            // 依次判断前面已排序好的元素(如果存在)是否需要往后挪动
            for(j = i - 2; array[j] > array[0]; j--){    // 注意是往数组的开头方向遍历, 故j--
                array[j+1] = array[j];                   // 把元素j往数组末尾方向移动一位
            }

            // 已经找到正确的插入位置, 将待插入元素丢进去即可
            array[j+1] = array[0];
        }
    }
}

void ShellSort(int array[], int n)
{
    int count;      // 一共使用多少个增量
    printf("Please enter the number of increment:\n");
    scanf("%d", &count);

    // 具体增量由用户指定
    int inc[count];
    printf("Please enter %d increment:\n", count);
    for(int i = 0; i < count; i++){
        scanf("%d", &inc[i]);
    }

    // 希尔排序: 按不同增量使用直接插入排序
    for(int i = 0; i < count; i++){
        ShellInsertSort(array, n, inc[i]);

        // debug: 检查一下完成一轮排序之后数组长啥样
        printf("第%d轮排序结果: ", i);
        for(int i = 1; i <= n; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
    }

}

// "希尔增量排序": 本质上也是直接插入排序, 但是这里可以指定增量
void ShellInsertSort(int array[], int n, int inc)
{
    // 从array[1+inc] 开始进行遍历, 与前面的所有元素进行比较, 由于数组是连续存放的, 故插入元素时需要挪动后面的所有元素
    int i, j;
    for (i = 1+inc; i <= n; i++){       // 考虑了增量问题, 故从 1+inc 开始; array 的 0位置 预留出来用于暂存插入元素, 故 i<=n
        if (array[i] < array[i-inc]){   // 考虑增量问题, 相当于进行了分组, 故比较的元素应该是 i-inc
            array[0] = array[i];
            array[i] = array[i-inc];

            // 依次判断前面已排序好的元素(如果存在)是否需要往后挪动
            for(j = i - inc - inc; (j > 0) && (array[j] > array[0]); j -= inc){    // 考虑增量问题, 注意进行排序的元素位置, 防止越界, j要大于0
                array[j+inc] = array[j];                         // 把元素j往数组中后面移动, 且注意是移动后后面的分组元素上
            }

            // 已经找到正确的插入位置, 将待插入元素丢进去即可
            array[j+inc] = array[0];
        }
    }
}