/*
 * 两个链表的第一个公共结点
 */
#include <cstdio>
#include <stack>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

Node *publicNode(Node *head1, Node *head2)
{
    if (head1 && head2)
    {
        stack<Node *> st1;
        stack<Node *> st2;
        Node *p1 = head1;
        Node *p2 = head2;
        Node *p = NULL; // 公共结点

        while (p1)
        {
            st1.push(p1);
            p1 = p1->next;
        }
        while (p2)
        {
            st2.push(p2);
            p2 = p2->next;
        }

        while (!st1.empty() && !st2.empty())
        {
            if (st1.top() == st2.top())
            {
                p = st1.top();
                st1.pop();
                st2.pop();
            }
            else
            {
                break;
            }
        }
        return p;
    }
    else
        return nullptr;
}

int main()
{
    // 手动创建2个链表
    Node *head1 = new Node(4);
    Node *head2 = new Node(5);
    Node *n1 = new Node(1);
    Node *n2 = new Node(0);
    Node *n3 = new Node(1);
    Node *u1 = new Node(8);
    Node *u2 = new Node(4);
    Node *u3 = new Node(5);
    head1->next = n1;
    head2->next = n2;
    n2->next = n3;
    n3->next = u1;
    n1->next = u1;
    u1->next = u2;
    u2->next = u3;

    // 找出第一个公共结点
    Node *p = publicNode(head1, head2);
    if (p)
    {
        printf("%d\n", p->val);
    }
    else
    {
        printf("None\n");
    }

    return 0;
}