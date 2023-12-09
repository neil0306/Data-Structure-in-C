#include "binary_tree.h"

int main(void)
{
    struct BinTree_node * myTree =  create_bintree();

    printf("-------------\n");
    printf("pre-order: ");
    pre_order(myTree);
    printf("\n");

    printf("-------------\n");
    printf("in-order: ");
    in_order(myTree);
    printf("\n");

    printf("-------------\n");
    printf("pos-order: ");
    pos_order(myTree);
    printf("\n");

    printf("-------------\n");
    printf("level traverse: ");
    level_traverse(myTree);
    printf("\n");

    return 0;
}
