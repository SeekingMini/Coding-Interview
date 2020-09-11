/*
 * 二叉树中和为某一值的路径
 */
#include <cstdio>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *lchild;
    Node *rchild;

    Node()
    {
        int val = -1;
        lchild = nullptr;
        rchild = nullptr;
    }
};

void pathSum(Node *root, int s, int sum, vector<int> &path)
{
    path.push_back(root->val);
    s += root->val;

    if (!root->lchild && !root->rchild)  
    { // 结点是叶子结点
        if (s == sum && path.size())
        {
            for (int i = 0; i < path.size(); i++)
                printf("%d ", path[i]);
            printf("\n");
            path.pop_back();
            return;
        }
        else
        {
            path.pop_back();
            return;
        }
    }
    else
    {
        if (root->lchild)
            pathSum(root->lchild, s, sum, path);
        if (root->rchild)
            pathSum(root->rchild, s, sum, path);
    }
    path.pop_back(); // 在返回父结点前，删除当前结点。

    return;
}

int main()
{
    vector<int> path;
    // 二叉树建树比较麻烦，所以手动建树。
    Node *root = new Node();
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();
    Node *n4 = new Node();
    Node *n5 = new Node();
    Node *n6 = new Node();
    Node *n7 = new Node();
    Node *n8 = new Node();
    Node *n9 = new Node();
    Node *n10 = new Node();
    root->val = 5;
    n1->val = 4;
    n2->val = 8;
    n3->val = 11;
    n4->val = 13;
    n5->val = 4;
    n6->val = 7;
    n7->val = 2;
    n8->val = 5;
    n9->val = 1;
    root->lchild = n1;
    root->rchild = n2;
    n1->lchild = n3;
    n2->lchild = n4;
    n2->rchild = n5;
    n3->lchild = n6;
    n3->rchild = n7;
    n5->lchild = n8;
    n5->rchild = n9;

    // 打印路径
    pathSum(root, 0, 22, path);

    return 0;
}