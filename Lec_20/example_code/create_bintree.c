#include <stdio.h>
#include <stdlib.h>

struct BinTree_node
{
    unsigned char elem;
    struct BinTree_node *ltree, *rtree;
};

struct BinTree_node * create_bintree();

int main(void)
{
    struct BinTree_node * myTree =  create_bintree();
    return 0;
}

struct BinTree_node * create_bintree(void)
{
    unsigned char flag;
    struct BinTree_node * tree;
    tree = (struct BinTree_node *)malloc(sizeof(struct BinTree_node));

    // 当前节点
    printf("Please enter the element:\n ");
    while((tree->elem = getchar()) == '\n');        // 当读取的字符不是回车时, 就会跳出while, 这样做可以防止读到缓冲区里可能在上一次输入残存的回车

    // 左子树
    printf("Do you want to l_tree for %c, (Y/N)? \n", tree->elem);
    while((flag = getchar()) == '\n');              // 防止读到回车
    if(flag == 'Y'){
        tree->ltree = create_bintree();
    }
    else{
        tree->ltree = NULL;
    }

    // 右子树
    printf("Do you want to r_tree for %c, (Y/N)? \n", tree->elem);
    while((flag = getchar()) == '\n');              // 防止读到回车
    if(flag == 'Y'){
        tree->rtree = create_bintree();
    }
    else{
        tree->rtree = NULL;
    }
    
    return tree;
}






