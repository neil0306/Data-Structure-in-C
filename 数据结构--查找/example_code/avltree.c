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
int search_avltree(struct AVLTree_node *tree, unsigned int num);     // 在二叉搜索树进行搜索

int GetAVLTreeHeight(struct AVLTree_node * tree);            // 统计二叉树高度
struct AVLTree_node * LL_Rotation(struct AVLTree_node *node);// LL型最小不平衡子树 ==> 右旋
struct AVLTree_node * RR_Rotation(struct AVLTree_node *node);// RR型最小不平衡子树 ==> 左旋
struct AVLTree_node * LR_Rotation(struct AVLTree_node *node);// LR型最小不平衡子树 ==> 先左旋, 再右旋
struct AVLTree_node * RL_Rotation(struct AVLTree_node *node);// RL型最小不平衡子树 ==> 先右旋, 再左旋

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
    

    // 从二叉搜索树中查找指定元素
    printf("Please enter a number you want to find in AVLtree: ");
    scanf("%d", &num);
    if (search_avltree(mytree, num)){
        printf("Find %d in mytree.\n", num);
    }
    else{
        printf("Cannot not find %d in mytree.\n", num);
    }

    // 往二叉搜索树中添加节点
    printf("Please enter a number you want to insert to the AVLTree: ");
    scanf("%d", &num);
    mytree = insert_avltree(mytree, num);
    in_order(mytree);
    printf("\n");

    printf("mytree->elem = %d\n", mytree->elem);  // 加入前面插入了100, 此时应该为22
    printf("mytree->ltree->elem = %d\n", mytree->ltree->elem);
    printf("mytree->rtree->elem = %d\n", mytree->rtree->elem);
    printf("mytree->ltree->ltree->elem = %d\n", mytree->ltree->ltree->elem);
    printf("mytree->rtree->rtree->elem = %d\n", mytree->rtree->rtree->elem);
    printf("mytree->ltree->ltree->ltree->elem = %d\n", mytree->ltree->ltree->ltree->elem);  // 这个应该为9
    printf("mytree->rtree->rtree->rtree->elem = %d\n", mytree->rtree->rtree->rtree->elem);  // 这个应该为100


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

        // 判断插入节点之后是否平衡(注意: 如果不平衡, 此时的T指针恰好指向失衡点)
        if(GetAVLTreeHeight(T->ltree) - GetAVLTreeHeight(T->rtree) > 1){
            if(elem < T->ltree->elem){  // 通过失衡点到新增节点的第二路径节点大小来区分是LL型还是LR型
                // 调整平衡 (LL型) ==> 右旋
                T = LL_Rotation(T);
            }
            else{
                // 调整平衡(LR型) ==> 先左旋, 再右旋
                T = LR_Rotation(T);
            }

        }
    }
    else if(elem > T->elem){        // 假如传进来的不是空树, 则比较一下elem与当前(子树)根节点的大小, 从而确定把它放到左子树还是右子树位置
        T->rtree = insert_avltree(T->rtree, elem);      // 利用递归的思想: 此时 rtree 必然是空树, 会直接走上面的if分支

        // 判断插入节点之后是否平衡
        if(GetAVLTreeHeight(T->rtree) - GetAVLTreeHeight(T->ltree) > 1){
            if(elem > T->rtree->elem){   // 通过失衡点到新增节点的第二路径节点大小来区分是RR型还是RL型
                // 调整平衡 (RR型) ==> 左旋
                T = RR_Rotation(T);
            }
            else{
                // 调整平衡 (RL型) ==> 先右旋, 再左旋
                T = RL_Rotation(T);
            }
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

    // step3: 让 temp的右子树 设置为 node 节点
    temp->rtree = node;

    return temp;
}

struct AVLTree_node * RR_Rotation(struct AVLTree_node *node)
{
    struct AVLTree_node * temp = NULL;

    // step1: node的右子树赋给 temp
    temp = node->rtree;

    // step2: node的右子树的左子树 挪动到 node的左子树位置
    node->rtree = node->rtree->ltree;

    // step3: temp的左子树 设置为 node 节点
    temp->ltree = node;

    return temp;
}

struct AVLTree_node * LR_Rotation(struct AVLTree_node *node)
{
    // 左子树部分先进行 "左旋"(当做是RR型) ==> 转换为 LL型 
    node->ltree = RR_Rotation(node->ltree);

    // 再对当前最小不平衡子树进行 "右旋"
    node = LL_Rotation(node);

    return node;
}

struct AVLTree_node * RL_Rotation(struct AVLTree_node *node)
{
    // 右子树部分先进行 "右旋"(当做是LL型) ==> 转换为 RR型 
    node->rtree = LL_Rotation(node->rtree);

    // 再对当前最小不平衡子树进行 "左旋"
    node = RR_Rotation(node);

    return node;
}

int search_avltree(struct AVLTree_node *tree, unsigned int num)
{
    struct AVLTree_node *p = tree;       // 指向当前遍历的节点

    while(p != NULL){
        if(num == p->elem){             // 找到想要的元素
            return 1;
        }
        else if(num < p->elem){         // 目标位于左子树
            p = p->ltree;               // p更新到左子树的根节点
        }
        else{
            p = p->rtree;               // 目标位于右子树
        }
    }
    return 0;
}





