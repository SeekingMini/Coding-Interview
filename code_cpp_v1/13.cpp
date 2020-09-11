/*
 * 在O(1)时间删除链表结点
 */
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node()
    {
        this->val = 0;
        this->next = nullptr;
    }
};

void deleteNode(Node *head, Node *node)
{
    if (!head || !node)
        return;

    // 删除的结点不是尾结点
    if (node->next)
    {
        Node *next_node = node->next;
        node->val = next_node->val;
        node->next = next_node->next;
        delete next_node;
        next_node = nullptr;
    }
    // 链表只有一个结点，删除头结点
    else if (head == node)
    {
        delete node;
        node = nullptr;
        head = nullptr;
    }
    // 删除的结点是尾结点
    else
    {
        Node *p = head->next;
        while (p->next != node)
        {
            p = p->next;
        }
        p->next = nullptr;
        delete node;
    }
}