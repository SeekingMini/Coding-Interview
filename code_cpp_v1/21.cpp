/*
 * 包含min函数的栈
 */
#include <stack>
#include <cstdio>
using namespace std;

class Stack
{
public:
    void push(int n)
    {
        s_data.push(n);
        if (n <= minNum)
        {
            minNum = n;
            s_assist.push(n);
        }
    }
    void pop()
    {
        int top = s_data.top();
        s_data.pop();
        if (top == this->minNum && !s_assist.empty())
        {
            s_assist.pop();
            this->minNum = s_assist.top();
        }
        if (s_data.empty())
        {
            this->minNum = INT32_MIN;
        }
    }
    int min()
    {
        return minNum;
    }

private:
    stack<int> s_data;
    stack<int> s_assist;
    int minNum = INT32_MAX;
};

int main()
{
    FILE *fp = fopen("../test-data/21.txt", "r");
    int length, n;
    Stack stack;

    // 读入数据
    fscanf(fp, "%d\n", &length);
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &n);
        stack.push(n);
        printf("%d ", n);
    }
    printf("\n");

    // 操作
    printf("min(stack) = %d\n", stack.min());
    printf("pop\n");
    stack.pop();
    printf("push -1\n");
    stack.push(-1);
    printf("min(stack) = %d\n", stack.min());
    printf("pop\n");
    stack.pop();
    printf("pop\n");
    stack.pop();
    printf("pop\n");
    stack.pop();
    printf("pop\n");
    stack.pop();
    printf("pop\n");
    stack.pop();
    printf("min(stack) = %d\n", stack.min());

    return 0;
}