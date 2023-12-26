#include <stdio.h>

#define SIZE 100

int SqSearch_Guard(int array[], int n, int x);

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

    i = SqSearch_Guard(arr, n, x);

    if(i == n){
        printf("Cannot find the element in your data.\n");
    }
    else{
        printf("The element you want to search is in %d position!\n", i);
    }

    return 0;
}

int SqSearch_Guard(int array[], int n, int x)
{
    int i;
    array[n] = x;       // 数组末尾增加哨兵

    for (i = 0; array[i] != x; i++);        // 这时候不再需要判断是否越界
    return i;
}