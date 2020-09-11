/*
 * 树的子结构
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

bool hasSubTree(Node *r1, Node *r2)
{
    bool res = false;

    if (r1 != NULL && r2 != NULL)
    {
        if (r1->val == r2->val)
        {
            res = tree1Hastree2(r1, r2);
        }
        if (!res)
            res = hasSubTree(r1->lchild, r2);
        if (!res)
            res = hasSubTree(r1->rchild, r2);
    }

    return res;
}

bool tree1Hastree2(Node *r1, Node *r2)
{
    if (r2 == NULL)
        return true;
    if (r1 == NULL)
        return false;
    if (r1->val != r2->val)
        return false;

    return tree1Hastree2(r1->lchild, r2->lchild) &&
           tree1Hastree2(r1->rchild, r2->rchild);
}