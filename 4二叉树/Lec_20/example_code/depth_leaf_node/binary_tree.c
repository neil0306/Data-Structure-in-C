#include "binary_tree.h"

struct BinTree_node * create_bintree(void)
{
    unsigned char flag;
    struct BinTree_node * tree;
    tree = (struct BinTree_node *)malloc(sizeof(struct BinTree_node));

    // 当前节点
    printf("Please enter the element:\n");
    while((tree->elem = getchar()) == '\n');        // 当读取的字符不是回车时, 就会跳出while, 这样做可以防止读到缓冲区里可能在上一次输入残存的回车

    // 左子树
    printf("Do you want to create l_tree for %c, (Y/N)? \n", tree->elem);
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

void pre_order(struct BinTree_node * tree)
{
    if(tree != NULL){   // 首先确保根节点是有效的二叉树结构
        printf("%c ", tree->elem);  // 中
        pre_order(tree->ltree);     // 左
        pre_order(tree->rtree);     // 右
    }
}

void in_order(struct BinTree_node * tree)
{
    if(tree != NULL){
        in_order(tree->ltree);      // 左
        printf("%c ", tree->elem);  // 中
        in_order(tree->rtree);      // 右
    }
}

void pos_order(struct BinTree_node * tree)
{
    if (tree != NULL){
        pos_order(tree->ltree);
        pos_order(tree->rtree);
        printf("%c ", tree->elem);
    }
}

void level_traverse(struct BinTree_node * tree)
{
    struct BinTree_node node;

    // 1. 根节点入队列
    enqueue(*tree);     // 注意: 入队列的不是指针, 而是结构体本身!

    // 2. 队列不为空时, 循环: 第一个元素出队列, 打印节点数据, 节点的左子树右子树依次入队列(如果有的话)
    while(!isEmpty()){  // 队列不为空时
        // 将第一个队列出队列, 并打印里面的数据
        node = dequeue();
        printf("%c ", node.elem);

        // 如果子树存在, 则 依次 将左子树和右子树入队
        if(node.ltree != NULL){
            enqueue(*node.ltree);       //入队列的是结构体本身(不是指针)
        }
        if (node.rtree != NULL) {
            enqueue(*node.rtree);       //入队列的是结构体本身(不是指针)
        }
    }
    printf("\n");
}

unsigned int depth(struct BinTree_node * tree)
{
    unsigned int l_depth = 0;
    unsigned int r_depth = 0;
    if(tree == NULL){       // 空二叉树的深度为0 (递归停止条件)
        return 0;
    }
    else{
        l_depth = depth(tree->ltree);       // 左子树的深度
        r_depth = depth(tree->rtree);       // 右子树的深度
        return (l_depth > r_depth) ? (l_depth + 1) : (r_depth + 1); // 当前二叉树的深度为最大的子树深度 + 1
    }
}

unsigned int leaf_num(struct BinTree_node * tree)
{
    if(tree == NULL){
        return 0;
    }
    else if(tree->ltree == NULL && tree->rtree == NULL){
        return 1;
    }
    else{
        return leaf_num(tree->ltree) + leaf_num(tree->rtree);
    }
}


unsigned int node_num(struct BinTree_node * tree)
{
    if(tree == NULL){
        return 0;
    }
    else{
        return node_num(tree->ltree) + node_num(tree->rtree) + 1;
    }
}


