#include <stdio.h>

#define SIZE 100

int SqSearch(int array[], int n, int x);

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

    i = SqSearch(arr, n, x);

    if(i == -1){
        printf("Cannot find the element in your data.\n");
    }
    else{
        printf("The element you want to search is in %d position!\n", i);
    }

    return 0;
}

int SqSearch(int array[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++){
        if(array[i] == x){
            return i;
        }
    }
    return -1;
}