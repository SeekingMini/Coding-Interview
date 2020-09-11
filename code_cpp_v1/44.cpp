/*
 * 扑克牌的顺子
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool isJunko(vector<int> &nums)
{
    if (nums.size() != 5)
        return false;

    sort(nums.begin(), nums.end()); // 数组排序
    int zero_times = 0;             // 0出现的次数

    // 检查有没有对子，如果有，则不是顺子。
    for (int i = 0; i < 4; i++)
    {
        if (nums[i] == nums[i + 1] && nums[i] != 0)
            return false;
    }

    // 统计0出现的次数
    for (int i = 0; i < 5; i++)
    {
        if (nums[i] != 0)
            break;
        else
            zero_times++;
    }

    // 检查是否可以成为顺子
    int gap = 0;
    for (int i = 0; i < 4; i++)
    {
        if (nums[i] != 0)
        {
            if (nums[i + 1] - nums[i] > 1)
            {
                gap += nums[i + 1] - nums[i] - 1;
            }
        }
    }
    if (gap <= zero_times)
        return true;
    else // 无法填补空缺
        return false;
}

int main()
{
    FILE *fp = fopen("../test-data/44.txt", "r");
    int length, n;
    vector<int> nums;

    // 读入数据
    fscanf(fp, "%d\n", &length);
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &n);
        nums.push_back(n);
    }

    // 打印
    for (int i = 0; i < length; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // 判断是不是顺子
    bool flag = isJunko(nums);
    if (flag)
    {
        printf("是顺子\n");
    }
    else
    {
        printf("不是顺子\n");
    }

    return 0;
}
