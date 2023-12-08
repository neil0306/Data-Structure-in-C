#include "loop_linklist.h"
#include <stdio.h>

int main(void)
{
    create_linklist(1);
    create_linklist(2);
    create_linklist(3);
    create_linklist(4);
    create_linklist(5);
    create_linklist(6);
    create_linklist(7);
    print_linklist(head);

    insert_node(0, 11);
    print_linklist(head);

    delete_node(6);
    print_linklist(head);

    delete_node(0);
    print_linklist(head);

    delete_node(0);
    print_linklist(head);

    delete_node(4);
    print_linklist(head);

    insert_node(0, 8);
    print_linklist(head);

    insert_node(5, 9);
    print_linklist(head);

    insert_node(2, 13);
    print_linklist(head);

    printf("%d\n",search(2));

    return 0;
}
