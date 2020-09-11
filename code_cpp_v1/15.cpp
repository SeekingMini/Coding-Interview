/*
 * 链表中倒数第k个结点
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

Node *getNum(Node *head, int k)
{
    if (head == NULL || k <= 0)
    {
        return NULL;
    }

    Node *p = head;
    for (int i = 0; i < k - 1; i++)
    {
        if (p->next != NULL)
        {
            p = p->next;
        }
        else
        {
            return NULL;
        }
    }
    Node *p_behind = head;
    while (p->next)
    {
        p = p->next;
        p_behind = p_behind->next;
    }

    return p_behind;
}

int main()
{
    FILE *fp = fopen("./15.txt", "r");
    int length, k;
    Node *head = new Node();

    // 读入数据
    fscanf(fp, "%d %d\n", &length, &k);
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

    Node *node = getNum(head, k);
    printf("%d\n", node->val);

    return 0;
}