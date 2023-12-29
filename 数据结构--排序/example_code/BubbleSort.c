#include <stdio.h>
#define SIZE 10 

void BubbleSort(int array[], int n);

int main(void)
{
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};

    printf("Original array: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 排序
    BubbleSort(arr, SIZE);

    printf("After sort: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void BubbleSort(int array[], int n)
{
    int i,j;
    int temp;

    for (i = 0; i < n-1; i++){              // n个元素只需要比较n-1次
        for (j = 0; j < n-1-i; j++){        // 内层循环要比外层少1次
            if(array[j] > array[j+1]){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}



