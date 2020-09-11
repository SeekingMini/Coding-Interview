/*
 * 二叉树的镜像
 */
#include <cstdio>
using namespace std;

struct Node
{
    char val;
    Node *lchild;
    Node *rchild;
    Node()
    {
        this->val = 0;
        this->lchild = nullptr;
        this->rchild = nullptr;
    }
};

void mirrowTree(Node *root)
{
    if (root == nullptr || (root->lchild == nullptr && root->rchild == nullptr))
        return;
        
    Node *node_tmp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = node_tmp;

    if (root->lchild)
        mirrowTree(root->lchild);
    if (root->rchild)
        mirrowTree(root->rchild);
}