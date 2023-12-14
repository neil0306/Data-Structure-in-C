#include <stdio.h>
#include <stdlib.h>

// 结构体 -- 二叉树节点
struct BinTree_node
{
    unsigned char elem;
    struct BinTree_node *ltree, *rtree;
};

// 函数声明
struct BinTree_node * create_bintree();         // 创建二叉树
void pre_order(struct BinTree_node * tree);     // 前序遍历
void in_order(struct BinTree_node * tree);      // 中序遍历
void pos_order(struct BinTree_node * tree);     // 后序遍历
struct BinTree_node * pre_in_CreateBinTree(char *pre, char *in, int len);    // pre: 先序遍历字符串起点; in: 中序遍历字符串起点, 当前二叉树的节点总数
struct BinTree_node * in_pos_CreateBinTree(char *in, char *post, int len);

int main(void)
{
    struct BinTree_node * myTree;

    char pre[100], in[100], post[100];
    int choose;
    int n;

    printf("1 Revert BinaryTree through pre & in order: \n");
    printf("2 Revert BinaryTree through in & post order: \n");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        printf("Please enter the number of nodes:");
        scanf("%d", &n);
        getchar();  // 去掉回车
        printf("Please enter the pre order: ");
        gets(pre);
        printf("Please enter the in order: ");
        gets(in);       // 会有警告, 但是只要输入不越界就没问题
        myTree = pre_in_CreateBinTree(pre, in, n);
        printf("After revert, show the BinTree in post order: ");
        pos_order(myTree);
        printf("\n");
        break;
    
    case 2:
        printf("Please enter the number of nodes: ");
        scanf("%d", &n);
        getchar();  // 去掉回车
        printf("Please enter the in order: ");
        gets(in);
        printf("Please enter the post order: ");
        gets(post);       // 会有警告, 但是只要输入不越界就没问题
        myTree = in_pos_CreateBinTree(in, post, n);
        printf("After revert, show the BinTree in pre order: ");
        pre_order(myTree);
        printf("\n");
        break;
    }
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

struct BinTree_node * pre_in_CreateBinTree(char *pre, char *in, int len)    // pre: 先序遍历字符串起点; in: 中序遍历字符串起点, 当前二叉树的节点总数
{
    struct BinTree_node *tree;  // 指向创建的二叉树
    char ch = pre[0];           // 二叉树根节点
    int index = 0;              // 用来查找 中序遍历结果 的根节点位置, 以确定左右子树的长度

    if(len == 0){               // 如果当前节点没有子树了, 就退出递归
        return NULL;
    }

    while(in[index] != ch){     // 当遍历的位置不是根节点时, 继续寻找; 循环结束时, index恰好为根节点的位置+1
        index++;
    }

    tree = (struct BinTree_node *)malloc(sizeof(struct BinTree_node));
    tree->elem = ch;
    tree->ltree = pre_in_CreateBinTree(pre+1, in, index);   // index恰好就是先序遍历结果的长度(左子树的长度), 注意index是从0开始计数的
    tree->rtree = pre_in_CreateBinTree(pre+index+1, in+index+1, len-index-1); // len-左子树长度-根节点, 得到的就是右子树的长度

    return tree;
}

struct BinTree_node * in_pos_CreateBinTree(char *in, char *post, int len)
{
    struct BinTree_node *tree;  // 指向创建的二叉树
    if(len == 0){
        return NULL;
    }
    char ch = post[len-1];      // 根节点为后序遍历结果的最后一个元素
    int index = 0;

    // 1. 先找到根节点在中序遍历中的位置, 以确定左右子树包含的节点元素有哪些
    while(in[index] != ch){
        index++;
    }

    // 2. 创建根节点
    tree = (struct BinTree_node *)malloc(sizeof(struct BinTree_node));
    tree->elem = ch;
    tree->ltree = in_pos_CreateBinTree(in, post, index);  // 左右子树部分丢进去, 左子树长度刚好为index
    tree->rtree = in_pos_CreateBinTree(in+index+1, post+index, len-index-1);

    return tree;
}
