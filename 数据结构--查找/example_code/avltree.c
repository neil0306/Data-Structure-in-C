#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// ------- 定义二叉查找树的节点结构体 ----------
struct AVLTree_node
{
    unsigned int elem;
    struct AVLTree_node *ltree, *rtree;
};

// -------------- 函数声明 ----------
struct AVLTree_node * create_avltree(unsigned int arr[], int n);
struct AVLTree_node * insert_avltree(struct AVLTree_node *T, unsigned int elem);
void in_order(struct AVLTree_node *tree);                    // 中序遍历
int GetAVLTreeHeight(struct AVLTree_node * tree);            // 统计二叉树高度
struct AVLTree_node * LL_Rotation(struct AVLTree_node *node);// LL型最小不平衡树 ==> 右旋

// ------------- main -------------
int main(void)
{
    unsigned int arr[SIZE] = {37, 22, 11, 82, 67, 9, 45, 91, 33, 52};
    struct AVLTree_node *mytree = NULL;
    unsigned int num;

    mytree = create_avltree(arr, SIZE);

    // 显式一下二叉树 -- 通过中序遍历
    in_order(mytree);
    printf("\n");
    
    return 0;
}

// ---------- 用数组内的元素创建二叉搜索树 -------------
struct AVLTree_node * create_avltree(unsigned int arr[], int n)
{
    struct AVLTree_node *tree = NULL;
    int i;

    for(i = 0; i < n; i++){
        tree = insert_avltree(tree, arr[i]);       // 往二叉树中插入新节点(按照大小排序插入子树)
    }
    return tree;
}

struct AVLTree_node * insert_avltree(struct AVLTree_node *T, unsigned int elem)
{
    // 如果传进来的是空树, 则: 创建根节点, 然后左右子树设置为空, 再将将它添作为新的树返回
    if(T == NULL){
        T = (struct AVLTree_node *)malloc(sizeof(struct AVLTree_node));       // 先开辟空间
        T->elem = elem;
        T->ltree = T->rtree = NULL;
    }
    else if(elem < T->elem){        // 假如传进来的不是空树, 则比较一下elem与当前(子树)根节点的大小, 从而确定把它放到左子树还是右子树位置
        T->ltree = insert_avltree(T->ltree, elem);      // 利用递归的思想: 此时 ltree 必然是空树, 会直接走上面的if分支

        // 判断插入节点之后是否平衡
        if(GetAVLTreeHeight(T->ltree) - GetAVLTreeHeight(T->rtree) > 1){
            // 调整平衡 (LL型) ==> 右旋
            if(elem < T->ltree->elem){
                T = LL_Rotation(T);
            }

        }
    }
    else if(elem > T->elem){        // 假如传进来的不是空树, 则比较一下elem与当前(子树)根节点的大小, 从而确定把它放到左子树还是右子树位置
        T->rtree = insert_avltree(T->rtree, elem);      // 利用递归的思想: 此时 rtree 必然是空树, 会直接走上面的if分支

        // 判断插入节点之后是否平衡
        if(GetAVLTreeHeight(T->rtree) - GetAVLTreeHeight(T->ltree) > 1){
            
        }
    }
    else{                           // 此时 elem == T->elem
        printf("Inserting repeat node is forbidden!\n");
        exit(0);
    }
    return T;
}

void in_order(struct AVLTree_node *tree)
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

// 计算当前输入的树的 "高度"
int GetAVLTreeHeight(struct AVLTree_node * tree)
{
    if(tree != NULL){
        if(tree->ltree == NULL && tree->rtree == NULL){     // 只有根节点
            return 1;
        }
        else if(GetAVLTreeHeight(tree->rtree) > GetAVLTreeHeight(tree->ltree)){
            return  GetAVLTreeHeight(tree->rtree) + 1;      // 如果右子树比左子树高, 则直接返回右子树高度 + 1  (由于采用了递归, 高度会被累计的)
        }
        else{                                               // 左子树高度 <= 右子树高度 
            return  GetAVLTreeHeight(tree->ltree) + 1;
        }
    }
    else{
        return 0;
    }
}

struct AVLTree_node * LL_Rotation(struct AVLTree_node *node)
{
    struct AVLTree_node * temp = NULL;      // temp 是调整后的新树的根节点

    /* 下面将以 temp节点 为轴, 进行右旋 */

    // step1: node的左子树 赋值给 temp (相当于备份了一下节点的地址)
    temp = node->ltree;

    // step2: 将 node的左子树的右子树 挪动到 node的左子树位置(第一步已经备份过地址, 这里可以安全地覆盖)
    node->ltree = node->ltree->rtree;

    // step3: 让 temp的左子树 设置为 node 节点
    temp->ltree = node;

    return temp;
}
