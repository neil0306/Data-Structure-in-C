#include <stdio.h>
#include "linklist.h"

int main(void)
{
    create_linklist('A');
    create_linklist('B');
    create_linklist('C');
    create_linklist('D');
    print_linklist();

    printf("-----\n");
    delete_node(0);
    print_linklist();

    printf("-----\n");
    insert_node(0, 'F');
    insert_node(2, 'Z');
    print_linklist();

    if(search('C')){
        printf("The element is found in the linklist.\n");
    }
    else{
        printf("Cannot find it.\n");
    }

    return 0;
}