/*
 * 反转链表
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

Node *reverse(Node *head)
{
    if (head == nullptr) // 链表为空
        return NULL;
    if (!head->next) // 链表只有一个结点
        return head;

    Node *p1 = head;       // 链表第1个结点
    Node *p2 = head->next; // 链表第2个结点
    head->next = nullptr;

    while (p2)
    {
        Node *p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    return p1;
}

int main()
{
    FILE *fp = fopen("./16.txt", "r");
    int length;
    Node *head = new Node();

    // 读入数据
    fscanf(fp, "%d\n", &length);
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

    // 反转链表
    Node *new_head = reverse(head);
    p = new_head;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}