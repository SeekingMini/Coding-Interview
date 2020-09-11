/*
 * 重建二叉树
 */
#include <cstdio>
using namespace std;

struct Node
{
    int val;
    Node *lchild;
    Node *rchild;
    Node()
    {
        this->val = -1;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

Node *ConstructTree(int *preorder, int *inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0)
    {
        return NULL;
    }
    Construct(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
Node *Construct(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
    Node *root = new Node();
    root->val = startPreorder[0]; // 前序数组的第一个值是根结点的值

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startInorder == *endInorder)
        {
            return root;
        }
        else
        {
            return;
        }
    }

    // 在中序遍历中找到根结点的值
    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != root->val)
    {
        rootInorder++;
    }
    if (rootInorder == endInorder && *rootInorder != root->val)
    {
        return;
    }
    int leftLength = rootInorder - startInorder; // 根结点的左子树节点个数
    int *leftPreorderEnd = startPreorder + leftLength;
    // 构建左子树
    if (leftLength > 0)
    {
        root->lchild = Construct(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    // 构建右子树
    if (leftLength < endPreorder - startPreorder)
    {
        root->rchild = Construct(leftPreorderEnd + 1, endPreorder, startInorder, endInorder);
    }

    return root;
}