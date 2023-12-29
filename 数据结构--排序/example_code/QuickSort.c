#include <stdio.h>
#define SIZE 10 

void QuickSort(int array[], int start, int end);

int main(void)
{
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};

    printf("Original array\t: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 排序
    QuickSort(arr, 0, SIZE-1);

    printf("After sort\t: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void QuickSort(int array[], int start, int end)
{
    int i = start, j = end;     // i在左, j在右; 基准元素是 start 位置的元素
    int temp;

    while(i < j){
        /* 划分效果: 左测元素 < 基准元素     右侧元素 >= 基准元素 */

        // 移动j, 寻找比i元素小的元素位置
        while(array[i] < array[j] && i < j){
            j--;
        }
        // 交换 array[i] 和 array[j]
        temp = array[j];
        array[j] = array[i];
        array[i] = temp;

        // 移动i, 找出比j元素大的元素位置
        while(array[i] <= array[j] && i < j){
            i++;
        }
        // 交换 array[i] 和 array[j]
        temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }

    /* 此时i指向基准元素, 递归处理左, 右两个部分 */
    // 递归结束条件
    if(i-1 > start){        // 保证基准点左侧还有元素
        QuickSort(array, start, i-1);
    }

    if(i+1 < end){          // 保证基准点右侧还有元素
        QuickSort(array, i+1, end);
    }

}



