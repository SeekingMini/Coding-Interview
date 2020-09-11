/*
 * 二叉树的深度
 */
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *lchild;
    Node *rchild;
    Node()
    {
        this->val = -1;
        lchild = nullptr;
        rchild = nullptr;
    }
};

void treeDepth(Node *root, vector<int> &depths, int d)
{
    if (!root)
    {
        depths.push_back(d - 1);
        return;
    }
    else
    {
        treeDepth(root->lchild, depths, d + 1);
        treeDepth(root->rchild, depths, d + 1);
    }
}

int main()
{
    vector<int> depths;
    // 二叉树建树比较麻烦，所以手动建树。
    Node *root = new Node();
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();
    Node *n4 = new Node();
    Node *n5 = new Node();
    Node *n6 = new Node();
    root->val = 1;
    n1->val = 2;
    n2->val = 3;
    n3->val = 4;
    n4->val = 5;
    n5->val = 6;
    n6->val = 7;
    root->lchild = n1;
    root->rchild = n2;
    n1->lchild = n3;
    n1->rchild = n4;
    n2->rchild = n5;
    n4->lchild = n6;

    // 计算最大深度
    treeDepth(root, depths, 1);
    auto maxDepth = max_element(depths.begin(), depths.end());
    cout << *maxDepth << endl;

    return 0;
}