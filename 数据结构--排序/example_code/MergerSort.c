#include <stdio.h>
#define SIZE 10 

void Divid_Merge_Sort(int array[], int start, int end);
void MergeSort(int array[], int start, int min, int end);

int main(void)
{
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};

    printf("Original array\t: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 排序
    Divid_Merge_Sort(arr, 0, SIZE-1);

    printf("After sort\t: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void Divid_Merge_Sort(int array[], int start, int end)
{
    int mid;
    if(start < end){        // 说明当前数组不止1个元素, 可以细分
        // step1: 分解
        mid = start/2 + end/2;
        Divid_Merge_Sort(array, start, mid);
        Divid_Merge_Sort(array, mid+1, end);

        // step: 合并排序
        MergeSort(array, start, mid, end);
    }
}

void MergeSort(int array[], int start, int mid, int end)
{
    int i, j, k;                 // i指向左半部分, j指向右半部分, k指向结果数组.
    int n1 = mid - start + 1;    // 左半部分元素个数
    int n2 = end - mid;          // 右半部分元素个数: end - (mid+1) + 1
    int left[n1];
    int right[n2];

    // 初始化临时数组
    for(int i = 0; i < n1; i++){
        left[i] = array[start + i];
    }
    for(int j = 0; j < n2; j++){
        right[j] = array[mid+1 + j];
    }

    i = j = 0;
    k = start;
    while(i < n1 && j < n2){
        if(left[i] < right[j]){
            array[k++] = left[i++];
        }
        else{
            array[k++] = right[j++];
        }
    }

    // 放入剩余内容
    while(i < n1){          // case: 左半部分还没放完
        array[k++] = left[i++];
    }
    while(j < n2){          // case: 右半部分还没放完
        array[k++] = right[j++];
    }
}
