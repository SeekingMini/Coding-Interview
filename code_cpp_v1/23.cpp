/*
 * 从上往下打印二叉树(宽度优先遍历二叉树)
 */
#include <cstdio>
#include <queue>
using namespace std;

struct Node
{
    char val;
    Node *lchild;
    Node *rchild;
    Node()
    {
        this->val = '#';
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

void BFS(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        printf("%c ", node->val);
        if (node->lchild)
            q.push(node->lchild);
        if (node->rchild)
            q.push(node->rchild);
    }
}