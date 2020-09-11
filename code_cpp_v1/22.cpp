/*
 * 栈的压入、弹出序列
 */
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;

bool isValidPop(const vector<int> &push, const vector<int> &pop)
{
    stack<int> st;
    int n = pop.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        st.push(push[i]);
        while (!st.empty() && j < n && st.top() == pop[j])
        {
            j++;
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    FILE *fp = fopen("../test-data/22.txt", "r");
    int length, n;

    // 读入数据
    fscanf(fp, "%d\n", &length);
    vector<int> push;
    vector<int> pop;
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &n);
        push.push_back(n);
    }
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &n);
        pop.push_back(n);
    }

    // 打印数据
    for (int i = 0; i < length; i++)
    {
        printf("%d ", push[i]);
    }
    printf("\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", pop[i]);
    }
    printf("\n");

    if (isValidPop(push, pop))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}