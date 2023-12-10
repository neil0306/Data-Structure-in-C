#include <stdio.h>
#include <stdlib.h>

// 结构体 -- 二叉树节点
struct BinTree_node
{
    unsigned char elem;
    struct BinTree_node *ltree, *rtree;
};

// 函数声明
struct BinTree_node * create_bintree();         // 创建二叉树(问询法)
struct BinTree_node * Create_Bintree_pre();     // 创建二叉树(补空法-前序遍历)
void pre_order(struct BinTree_node * tree);     // 前序遍历
void in_order(struct BinTree_node * tree);      // 中序遍历
void pos_order(struct BinTree_node * tree);     // 后序遍历

int main(void)
{
    // struct BinTree_node * myTree =  create_bintree();

    printf("Please input a pre-order binary tree(with fill blank #)\n");
    struct BinTree_node * myTree =  Create_Bintree_pre();

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

    return 0;
}

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

struct BinTree_node * Create_Bintree_pre()
{
    char ch;
    struct BinTree_node * tree;
    scanf("%c", &ch);
    if(ch == '#'){          // 递归停止条件
        tree = NULL;
    }
    else{                   // 递归过程
        tree = (struct BinTree_node *)malloc(sizeof(struct BinTree_node));
        tree->elem = ch;
        tree->ltree = Create_Bintree_pre();     // 递归创建左子树
        tree->rtree = Create_Bintree_pre();     // 递归创建右子树
    }
    return  tree;
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


