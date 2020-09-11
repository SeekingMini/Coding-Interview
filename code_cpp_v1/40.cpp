/*
 * 数组中只出现一次的数字
 */
#include <cstdio>
#include <vector>
using namespace std;

void getTwoNumbers(const vector<int> nums, vector<int> &part1, vector<int> &part2, vector<int> &two)
{
    // 第一遍异或运算
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        res ^= nums[i];
    }

    // 找到res二进制表示中第一个为1的位
    int one = 0x1;
    int pos = 1;
    while (true)
    {
        if ((res & one) == 0)
        {
            pos++;
            res >>= 1;
        }
        else
            break;
    }

    // 产生一个二进制数满足从右向左数只有第pos位为1
    int i = 0;
    while (i < pos - 1)
    {
        one <<= 1;
        i++;
    }

    // 把数组分为两组
    for (i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & one) == 0)
        {
            part1.push_back(nums[i]);
        }
        else
        {
            part2.push_back(nums[i]);
        }
    }

    // 在两个子数组中分别找到只出现一次的数字
    res = 0;
    for (i = 0; i < part1.size(); i++)
    {
        res ^= part1[i];
    }
    two.push_back(res);
    res = 0;
    for (i = 0; i < part2.size(); i++)
    {
        res ^= part2[i];
    }
    two.push_back(res);
}

int main()
{
    FILE *fp = fopen("../test-data/40.txt", "r");
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
    for (int i = 0; i < nums.size(); i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // 找个两个只出现一次的数字
    vector<int> part1, part2, two;
    getTwoNumbers(nums, part1, part2, two);
    printf("%d %d\n", two[0], two[1]);

    return 0;
}