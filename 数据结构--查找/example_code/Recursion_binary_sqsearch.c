#include <stdio.h>

#define SIZE 100

int Recursion_Binary_SqSearch(int array[], int x, int low, int high);

int main(void)
{
    int n;
    int i;
    int arr[SIZE];
    int x;

    printf("Please enter the number of your data: \n");
    scanf("%d", &n);
    printf("Please enter the element of your data: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Please enter the element you want to search:");
    scanf("%d", &x);

    // 使用递归写法的二分查找
    i = Recursion_Binary_SqSearch(arr, x, 0, n-1);

    if(i == -1){
        printf("Cannot find the element in your data.\n");
    }
    else{
        printf("The element you want to search is in %d position!\n", i);
    }

    return 0;
}

int Recursion_Binary_SqSearch(int array[], int x, int low, int high)
{
    /* 这里划分区间使用的规则是 "左闭右闭" 区间 */
    int middle = (low >> 1) + (high >> 1);

    if(low > high){     // 这里的条件直接使用迭代写法的 while 条件的 "取反条件" 即可
        return -1;
    }

    if(x == array[middle]){
        return middle; 
    }
    else if(x > array[middle]){
        low = middle +1;
        return Recursion_Binary_SqSearch(array, x, middle+1, high);
    }
    else{
        return Recursion_Binary_SqSearch(array, x, middle, high-1);
    }
}