#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// ------- 定义二叉查找树的节点结构体 ----------
struct BSTree_node
{
    unsigned int elem;
    struct BSTree_node *ltree, *rtree;
};

// -------------- 函数声明 ----------
struct BSTree_node * create_BStree(unsigned int arr[], int n);
struct BSTree_node * insert_bstree(struct BSTree_node *T, unsigned int elem);
void in_order(struct BSTree_node *tree);            // 中序遍历

// ------------- main -------------
int main(void)
{
    unsigned int arr[SIZE] = {37, 22, 11, 82, 67, 9, 45, 91, 33, 52};
    struct BSTree_node *mytree = NULL;

    mytree = create_BStree(arr, SIZE);

    // 显式一下二叉树 -- 通过中序遍历
    in_order(mytree);
    printf("\n");
    return 0;
}

// ---------- 用数组内的元素创建二叉搜索树 -------------
struct BSTree_node * create_BStree(unsigned int arr[], int n)
{
    struct BSTree_node *tree = NULL;
    int i;

    for(i = 0; i < n; i++){
        tree = insert_bstree(tree, arr[i]);       // 往二叉树中插入新节点(按照大小排序插入子树)
    }
    return tree;
}

struct BSTree_node * insert_bstree(struct BSTree_node *T, unsigned int elem)
{
    // 如果传进来的是空树, 则: 创建根节点, 然后左右子树设置为空, 再将将它添作为新的树返回
    if(T != NULL){
        T = (struct BSTree_node *)malloc(sizeof(struct BSTree_node));       // 先开辟空间
        T->elem = elem;
        T->ltree = T->rtree = NULL;
    }
    else if(elem < T->elem){        // 假如传进来的不是空树, 则比较一下elem与当前(子树)根节点的大小, 从而确定把它放到左子树还是右子树位置
        T->ltree = insert_bstree(T->ltree, elem);      // 利用递归的思想: 此时 ltree 必然是空树, 会直接走上面的if分支
    }
    else if(elem > T->elem){        // 假如传进来的不是空树, 则比较一下elem与当前(子树)根节点的大小, 从而确定把它放到左子树还是右子树位置
        T->rtree = insert_bstree(T->rtree, elem);      // 利用递归的思想: 此时 rtree 必然是空树, 会直接走上面的if分支
    }
    else{                           // 此时 elem == T->elem
        printf("Inserting repeat node is forbidden!\n");
        exit(0);
    }
    return T;
}

void in_order(struct BSTree_node *tree)
{
    if(tree != NULL){
        // 左子树
        in_order(tree->ltree);      
        // 根节点      
        printf("%d ", tree->elem);
        // 右子树
        in_order(tree->rtree);
    }
}