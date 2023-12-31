#include <stdio.h>
#define SIZE 10 

void HeapkSort(int array[], int n);     // n 是数组最大下标
void Sink(int array[], int k, int n);   // 将节点k进行下沉(k是子二叉树根节点), n表示数组最大下标
void Swap(int * a, int *b);             // 交换节点元素


int main(void)
{
    int arr[SIZE] = {13, 4, 18, 31, 29, 12, 18, 22, 8, 21};

    printf("Original array\t: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 排序
    HeapkSort(arr, SIZE-1);

    printf("After sort\t: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void HeapkSort(int array[], int n)
{
    // step1: 创建初始堆
    for(int i = (n-1)/2; i >=0; i--){
        Sink(array, i, n);          // 对每一个遍历的节点都调用下沉函数(只有满足条件的节点才会下沉)
    }

    // step2: 调整堆结构
    while(n > 0){
        // 交换: 堆顶元素 与 堆底元素 交换
        Swap(&array[0], &array[n]);
        // 将刚操作的元素锁定 (已排序不能再操作)
        n--;
        // 下沉: 此时的堆顶元素下沉
        Sink(array, 0, n);

    }
}

void Sink(int array[], int k, int n)
{
    while( 2*k + 1 <= n){                       // 检查有没有左子树, 如有, 则进入循环
        int j = 2*k + 1;                        // j此时表示当前遍历到的左子树节点

        // 找左右子树中最大的节点下标
        if( j < n && array[j] < array[j+1]){    // j < n 说明一定有右子树; 右子树比左子树大
            j++;                                // j此时改为右子树节点
        }

        // 根节点与左右子树最大者进行比较
        if(array[k] > array[j]){                // 根节点比左右子树都大, 此时不需要下沉
            break;
        }
        else{
            Swap(&array[k], &array[j]);         // 交换节点元素, 注意传入的是地址! 
        }

        // 更新当前遍历的根节点
        k = j;
    }
}

void Swap(int * a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
