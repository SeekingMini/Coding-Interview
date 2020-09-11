/*
 * 从尾到头打印链表
 */
#include <cstdio>
#include <stack>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node()
    {
        this->val = -1;
        this->next = NULL;
    }
};

void printReverse(Node *head)
{
    if (head == nullptr)
        return;

    stack<Node *> nodes;
    Node *p = head;
    while (p->next)
    {
        p = p->next;
        nodes.push(p);
    }
    while (!nodes.empty())
    {
        p = nodes.top();
        printf("%d ", p->val);
        nodes.pop();
    }
}

void printReverse_recursion(Node *head)
{
    if (head == NULL)
        return;

    if (head->next == nullptr)
    {
        printf("%d ", head->val);
        return;
    }
    else
    {
        printReverse_recursion(head->next);
        printf("%d ", head->val);
    }
}

int main()
{
    int length;
    FILE *fp = fopen("../test-data/5.txt", "r");

    // 读入数据
    fscanf(fp, "%d\n", &length);
    Node *head = new Node(); // 我们假设头结点不存值
    Node *p = head;
    for (int i = 0; i < length; i++)
    {
        Node *n = new Node();
        fscanf(fp, "%d ", &n->val);
        p->next = n;
        p = p->next;
    }

    // 打印数据
    p = head;
    while (p->next)
    {
        p = p->next;
        printf("%d ", p->val);
    }
    printf("\n");

    // 逆序打印数据(递归版)
    printReverse_recursion(head->next);
    printf("\n");

    return 0;
}