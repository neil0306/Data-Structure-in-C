#include <stdio.h>
#include <stdlib.h>

// 结构体 -- 二叉树节点
struct BinTree_node
{
    unsigned char elem;
    struct BinTree_node *ltree, *rtree;

    // 线索二叉树新增两个标志位
    int lflag, rflag;
};

struct BinTree_node * pre = NULL;         // 中序线索化二叉树需要使用的指针, 指向当前遍历节点的前趋点

// 函数声明
struct BinTree_node * create_bintree();         // 创建二叉树(问询法)
struct BinTree_node * Create_Bintree_pre();     // 创建二叉树(补空法-前序遍历)
void pre_order(struct BinTree_node * tree);     // 前序遍历
void in_order(struct BinTree_node * tree);      // 中序遍历
void pos_order(struct BinTree_node * tree);     // 后序遍历
void In_order_thread(struct BinTree_node *tree);            // 完成中序线索化的递归过程
void Create_InOrder_Thread(struct BinTree_node * T);        // 完成整个中序线索化
void Traverse_InOrder_Thread(struct BinTree_node * tree);   // 遍历中序线索化二叉树

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
    printf("creating in-order thread.... ");
    Create_InOrder_Thread(myTree);
    printf("\n");

    printf("-------------\n");
    printf("Traverse InOrder Thread tree: \n");
    Traverse_InOrder_Thread(myTree);

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

void In_order_thread(struct BinTree_node *tree)
{
    if(tree != NULL){
        // 1. 中序线索化左子树 (do in-order-thread to ltree)
        In_order_thread(tree->ltree);

        // 2. 处理根节点(do with current node)
        if(tree->ltree == NULL){    // 当前节点的左子树不存在时
            tree->lflag = 1;        // 此时左子树指针将指向前趋点
            // 让当前节点的左子树指向前趋点
            tree->ltree = pre;      // pre是全局变量
        }
        else{
            tree->lflag = 0;        // 左子树存在时
        }

        if(pre != NULL){     
            if(pre->rtree == NULL){ // 前趋点的右子树为空时
                pre->rflag = 1;     // 此时右子树将指向当前节点
                // 让前趋点的有指针域指向当前节点
                pre->rtree = tree;
            }
            else{
                pre->rflag = 0;     // 这种情况发生在中序遍历的起点(树的最左下节点)
            }
        }
        pre = tree;                 // 更新前趋点位置    
        /*
            注: 当前遍历的节点的更新在递归时完成(因为传参的时候传的是 tree->rtree, tree->ltree)
        */

        // 3. 中序线索化右子树 (do in-order-thread to rtree)
        In_order_thread(tree->rtree);
    }

}

void Create_InOrder_Thread(struct BinTree_node * T)
{
    if (T != NULL){
        In_order_thread(T);
        pre->rtree = NULL;          // 当走完中序线索化之后, pre指向的节点会停在中序遍历的最后一个节点, 此时这个节点的右子树应设置为NULL
        pre->rflag = 1;
    }
}

void Traverse_InOrder_Thread(struct BinTree_node * tree)
{
    while(tree != NULL){
        // step 1: 先找到二叉树的 "最左下节点"
        while(tree->lflag == 0){
            tree = tree->ltree;
        }
        printf("%c ", tree->elem);

        // step 2: 然后找到第一个节点的后继节点
        // case1: 这个节点没有右子树 ==> 直接把这个右子树的数据输出即可
        while((tree->rflag == 1) && (tree->rtree != NULL)){ // tree 没有右子树(flag为1), 此时它的 rtree 指针要么指向NULL(二叉树末尾), 要么指向后继节点
            tree = tree->rtree;
            printf("%c ", tree->elem);
        }
        
        // case2: 这个节点有右子树 ==> 把这棵右子树进行中序遍历, 中序遍历得到的第一个节点就是后继节点(右子树的 "最左下节点" ==> 又回到了第一步)
        tree = tree->rtree;         // 当前节点有右子树, 所以当前节点并没有直接连接着它的后继节点, 所以这里需要更新一下遍历的节点位置, 对于这个case, 输出后继点的任务是交给 step1 来完成的
    }
    printf("\n");
}