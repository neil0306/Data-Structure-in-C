#include "linklist.h"
#include <stdio.h>

int main(void)
{
    create_linklist(1);
    create_linklist(2);
    create_linklist(8);
    create_linklist(2);
    create_linklist(3);
    create_linklist(9);
    create_linklist(4);
    create_linklist(6);
    create_linklist(4);
    create_linklist(8);
    create_linklist(7);
    create_linklist(5);
    create_linklist(2);
    create_linklist(9);
    create_linklist(6);
    print_linklist(head);

    delete_repeat(head);
    print_linklist(head);

    return 0;
}
