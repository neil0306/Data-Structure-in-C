#ifndef __BinTree_CPP_H__
#define __BinTree_CPP_H__
#include <iostream>

using namespace std;

template <class U>
struct BinTree_node
{
    U elem;
    struct BinTree_node * ltree, *rtree;
    // 构造函数(结构体也有构造函数)
    BinTree_node() : ltree(nullptr), rtree(nullptr){}
    BinTree_node(U x, BinTree_node * l, BinTree_node * r) : elem(x), ltree(l), rtree(r){}
};

template <class T>
class BinTree
{
    private:
        BinTree_node<T> * root;

    public:
        BinTree() : root(nullptr) {};
        ~BinTree();                     // 析构需要用到遍历二叉树的知识, 暂时不写

        BinTree_node<T> * create_tree();
};

template<class T>
BinTree_node<T> * BinTree<T>::create_tree()
{
    unsigned char flag;
    BinTree_node<T> * tree = new BinTree_node<T>;

    // 当前节点数据
    cout << "Please enter the element:" << endl;
    while((tree->elem = cin.get()) == '\n');

    // 左子树
    cout << "Do you want to create ltree for " << tree->elem << ", (Y/N)? " << endl;
    while((flag = cin.get()) == '\n');
    if(flag == 'Y'){
        tree->ltree = create_tree();
    }
    else{
        tree->ltree = nullptr;
    }

    // 右子树
        // 左子树
    cout << "Do you want to create rtree for " << tree->elem << ", (Y/N)? " << endl;
    while((flag = cin.get()) == '\n');
    if(flag == 'Y'){
        tree->rtree = create_tree();
    }
    else{
        tree->rtree = nullptr;
    }

    return tree;
}


#endif //!__BinTree_CPP_H__