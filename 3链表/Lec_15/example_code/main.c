#include "linklist.h"
#include <stdio.h>

int main(void)
{
    int n = 0;
    create_linklist(1);
    create_linklist(2);
    create_linklist(3);
    create_linklist(4);
    create_linklist(5);
    create_linklist(6);
    create_linklist(7);
    create_linklist(8);
    create_linklist(9);
    create_linklist(10);
    print_linklist(head);

    printf("Please enter the last one you want to show: ");
    scanf("%d", &n);
    printf("the last n: %d\n", find_last_nth(head, n));
    return 0;
}
