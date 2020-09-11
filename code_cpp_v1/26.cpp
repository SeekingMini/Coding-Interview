/*
 * 复杂链表的复制
 */
#include <cstdio>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *any;
    Node()
    {
        val = -1;
        next = nullptr;
        any = nullptr;
    }
};

// 复制结点
void copyNodes(Node *head)
{
    Node *p = head;
    while (p)
    {
        Node *p_copied = new Node();
        p_copied->val = p->val;
        p_copied->next = p->next;
        p->next = p_copied;
        p = p_copied->next;
    }
}

// 复制指向任意结点的指针
void connectNodes(Node *head)
{
    Node *p = head;
    while (p)
    {
        Node *p_copied = p->next;
        if (p->any)
            p_copied->any = p->any->next;
        p = p_copied->next;
    }
}

// 分离链表
Node *splitNodes(Node *head)
{
    Node *p = head;
    Node *head_copied = nullptr;
    Node *p_copied = nullptr;
    if (p)
    {
        head_copied = p_copied = p->next;
        p->next = p_copied->next;
        p = p->next;
    }
    while (p)
    {
        p_copied->next = p->next;
        p_copied = p_copied->next;
        p->next = p_copied->next;
        p = p->next;
    }

    return head_copied;
}

Node *clone(Node *head)
{
    copyNodes(head);
    connectNodes(head);
    Node *new_head = splitNodes(head);

    return new_head;
}

int main()
{
    FILE *fp = fopen("../test-data/26.txt", "r");
    int length, n;

    // 读入数据
    fscanf(fp, "%d\n", &length);
    Node *head = new Node();
    Node *p = head;
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &p->val);
        if (i != length - 1)
        {
            Node *node = new Node();
            p->next = node;
            p = p->next;
        }
    }

    // 打印数据
    p = head;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    // 复制并打印新链表
    Node *new_head = clone(head);
    p = new_head;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}