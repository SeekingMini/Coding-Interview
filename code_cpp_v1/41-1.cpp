/*
 * 和为s的两个数字
 */
#include <cstdio>
#include <vector>
using namespace std;

vector<int> pairSum(const vector<int> &nums, int s)
{
    vector<int> pair;
    if (!nums.size())
    {
        return pair;
    }
    int p1 = 0;               // 指向数组第1个元素
    int p2 = nums.size() - 1; // 指向数组最后一个元素

    while (p1 < p2)
    {
        if (nums[p1] + nums[p2] == s)
        {
            pair.push_back(nums[p1]);
            pair.push_back(nums[p2]);
            return pair;
        }
        else if (nums[p1] + nums[p2] < s)
        {
            p1++;
        }
        else
        {
            p2--;
        }
    }
    return pair;
}

int main()
{
    FILE *fp = fopen("../test-data/41-1.txt", "r");
    int length, n, s;
    vector<int> nums;

    // 读入数据
    fscanf(fp, "%d %d\n", &length, &s);
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &n);
        nums.push_back(n);
    }

    // 打印数组
    for (int i = 0; i < nums.size(); i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // 查找数对
    vector<int> pair = pairSum(nums, s);
    if (!pair.size())
    {
        printf("没有找到数对！\n");
    }
    else
    {
        printf("%d %d\n", pair[0], pair[1]);
    }

    return 0;
}