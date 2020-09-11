/*
 * 二叉搜索树与双向链表
 */
#include <cstdio>
#include <list>
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

void convert(Node *root, list<int> &nodes)
{
    if (root)
    {
        convert(root->lchild, nodes);
        nodes.push_back(root->val);
        convert(root->rchild, nodes);
    }
}

int main()
{
    list<int> nodes;
    // 二叉树建树比较麻烦，所以手动建树。
    Node *root = new Node();
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();
    Node *n4 = new Node();
    Node *n5 = new Node();
    Node *n6 = new Node();
    root->val = 10;
    n1->val = 6;
    n2->val = 14;
    n3->val = 4;
    n4->val = 8;
    n5->val = 12;
    n6->val = 16;
    root->lchild = n1;
    root->rchild = n2;
    n1->lchild = n3;
    n1->rchild = n4;
    n2->lchild = n5;
    n2->rchild = n6;

    // 打印
    list<int>::iterator itr;
    convert(root, nodes);
    for (itr = nodes.begin(); itr != nodes.end(); itr++)
    {
        printf("%d ", *itr);
    }
    printf("\n");

    return 0;
}