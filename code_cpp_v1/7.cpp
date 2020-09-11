/*
 * 用两个栈实现队列
 */
#include <cstdio>
#include <stack>
using namespace std;

class Queue
{
public:
    void appendTail(const int node)
    {
        s1.push(node);
    }
    int deleteHead()
    {
        if (!s1.size())
        {
            return -1;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int node = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return node;
    }

private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    Queue q;
    FILE *fp = fopen("../test-data/7.txt", "r");
    int length;

    // 读入数据
    fscanf(fp, "%d ", &length);
    for (int i = 0; i < length; i++)
    {
        int node;
        fscanf(fp, "%d ", &node);
        q.appendTail(node);
    }

    // 队列操作
    printf("add 3\n");
    q.appendTail(3);
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());
    printf("remove top\n");
    printf("top = %d\n", q.deleteHead());

    return 0;
}