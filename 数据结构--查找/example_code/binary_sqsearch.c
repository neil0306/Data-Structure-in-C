#include <stdio.h>

#define SIZE 100

int Binary_SqSearch(int array[], int n, int x);

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

    i = Binary_SqSearch(arr, n, x);

    if(i == -1){
        printf("Cannot find the element in your data.\n");
    }
    else{
        printf("The element you want to search is in %d position!\n", i);
    }

    return 0;
}

int Binary_SqSearch(int array[], int n, int x)
{
    /* 这里划分区间使用的规则是 "左闭右闭" 区间 */
    int low = 0;
    int high = n - 1;  
    int middle;
    
    while(low <= high){         // 左闭右闭区间, 区间两边的index都是有合法元素的
        middle = (int)(low*0.5 + high * 0.5);       // 防止加法溢出, 先除以2
        // middle = (low >> 1) + (high >> 1);       // 在二进制中, 右移一位相当于除以2再取整

        if(x == array[middle]){
            return middle; 
        }
        else if(x > array[middle]){
            low = middle +1;
        }
        else{
            high = middle -1;
        }
    }
    return -1;
}