/*
 * 最小的k个数
 */
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> minK(const vector<int> arr, int k)
{
    priority_queue<int> q; // 队首元素一定是队列的最小值
    vector<int> res;
    if (k <= 0)
        return res;
    if (k >= arr.size())
        return arr;

    // 遍历数组
    for (int i = 0; i < arr.size(); i++)
    {
        int n = arr[i];
        if (q.size() < k)
        {
            q.push(n);
        }
        else
        {
            if (n < q.top())
            {
                q.pop();
                q.push(n);
            }
        }
    }

    // 把元素添加进数组
    while (!q.empty())
    {
        res.push_back(q.top());
        q.pop();
    }

    return res;
}

int main()
{
    FILE *fp = fopen("../test-data/30.txt", "r");
    int length, k, n;
    vector<int> arr;

    // 读入数据
    fscanf(fp, "%d %d\n", &length, &k);
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &n);
        arr.push_back(n);
    }

    // 打印数组
    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 计算结果
    vector<int> nums = minK(arr, k);
    for (int n : nums)
        printf("%d ", n);
    printf("\n");

    return 0;
}