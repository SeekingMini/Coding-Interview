/*
 * 连续子数组的最大和
 */
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    if (nums.size() <= 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];

    // dp[i]表示到nums[i]为止连续子数组的最大和
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (dp[i - 1] >= 0)
            dp[i] = dp[i - 1] + nums[i];
        else
            dp[i] = nums[i];
    }
    int max_sum = *max_element(dp.begin(), dp.end());

    return max_sum;
}

int main()
{
    FILE *fp = fopen("../test-data/31.txt", "r");
    int length, n;
    vector<int> nums;

    // 读入数据
    fscanf(fp, "%d\n", &length);
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

    // 计算连续子数组的最大和
    int max_sum = maxSubArray(nums);
    printf("%d\n", max_sum);

    return 0;
}