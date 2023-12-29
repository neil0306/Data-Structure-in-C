#include <stdio.h>
#define SIZE 10 

void SimpleSelectSort(int array[], int n);

int main(void)
{
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};

    printf("Original array\t: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 排序
    SimpleSelectSort(arr, SIZE);

    printf("After sort\t: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void SimpleSelectSort(int array[], int n)
{
    int i;          // 指向已排序序列的末尾, 也指向当前遍历的元素
    int j;          // 指向未排序序列的起始位置.
    int min;        // 存放每一轮循环中最小元素的下标 
    int temp;

    for(i = 0; i < n-1; i++){
        min = i;                        // 假设一开始 i 就是最小的元素
        for(j = i+1; j < n; j++){       // 从i后一个开始比较, 找符合条件的元素
            if(array[j] < array[min]){
                min = j;
            }
        }

        // 将最小的元素放到已排序序列末尾
        if(i != min){                   // i如果是最小元素, 就没必要交换了
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}
