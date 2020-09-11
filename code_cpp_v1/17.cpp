/*
 * 合并两个排序链表
 */
#include <cstdio>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node()
    {
        val = 0;
        next = nullptr;
    }
};

// 递归法
Node *merge_recursion(Node *h1, Node *h2)
{
    if (h1 == nullptr)
        return h2;
    if (h2 == nullptr)
        return h1;

    Node *p = NULL;
    if (h1->val < h2->val)
    {
        p = h1;
        p->next = merge_recursion(h1->next, h2);
    }
    else
    {
        p = h2;
        p->next = merge_recursion(h1, h2->next);
    }

    return p;
}

int main()
{
    FILE *fp = fopen("./17.txt", "r");
    int l1, l2;
    Node *head1 = new Node();
    Node *head2 = new Node();

    // 读入数据
    fscanf(fp, "%d %d\n", &l1, &l2);
    Node *p = head1;
    for (int i = 0; i < l1; i++)
    {
        fscanf(fp, "%d ", &p->val);
        if (i != l1 - 1)
        {
            Node *node = new Node();
            p->next = node;
            p = p->next;
        }
    }
    p = head2;
    for (int i = 0; i < l2; i++)
    {
        fscanf(fp, "%d ", &p->val);
        if (i != l2 - 1)
        {
            Node *node = new Node();
            p->next = node;
            p = p->next;
        }
    }

    // 打印数据
    p = head1;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    p = head2;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    // 合并链表
    Node *new_head = merge_recursion(head1, head2);
    p = new_head;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}