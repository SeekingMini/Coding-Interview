/*
 * 数组中的逆序对
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int i, int j)
{
    return i > j;
}

int reversePairs(vector<int> &nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return 0;
    if (nums.size() == 2)
    {
        if (nums[0] == nums[1])
            return 0;
        else
            return 1;
    }

    int count = 0;
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[j - 1])
                count++;
        }
    }

    return count;
}

int main()
{
    FILE *fp = fopen("../test-data/36.txt", "r");
    int length, n;
    vector<int> nums;

    // 读入数据
    fscanf(fp, "%d\n", &length);
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &n);
        nums.push_back(n);
    }

    // 打印数据
    for (int i = 0; i < nums.size(); i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // 计算逆序对
    int count = reversePairs(nums);
    printf("%d\n", count);

    return 0;
}
