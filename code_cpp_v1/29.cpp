/*
 * 数组中出现次数超过一半的数字
 */
#include <cstdio>
#include <vector>
using namespace std;

int major(const vector<int> nums)
{
    if (!nums.size())
        return -1;
    if (nums.size() == 1)
        return nums[0];

    int n = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == n)
            count++;
        else
        {
            count--;
            if (count == 0)
            {
                count = 1;
                n = nums[i];
            }
        }
    }
    if (count <= 0)
        return -1;
    else
        return n;
}

int main()
{
    FILE *fp = fopen("../test-data/29.txt", "r");
    int length, n;
    vector<int> nums;

    // 读入数据
    fscanf(fp, "%d ", &length);
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

    // 计算结果
    printf("%d\n", major(nums));

    return 0;
}