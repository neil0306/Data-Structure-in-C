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
    printf("before reverse: ");
    print_linklist(head);

    printf("After reverse: ");
    reverse_linklist(head);
    print_linklist(head);

    return 0;
}
