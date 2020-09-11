/*
 * 数字在排序数组中出现的次数
 */
#include <cstdio>
#include <vector>
using namespace std;

int firstK_recursion(const vector<int> nums, int n, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    int num_mid = nums[mid];
    if (num_mid == n)
    {
        if ((mid > 0 && nums[mid - 1] != n) || mid == 0)
        {
            return mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    else if (num_mid > n)
    {
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }

    return firstK_recursion(nums, n, low, high);
}

int lastK_recursion(const vector<int> nums, int n, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    int num_mid = nums[mid];
    if (num_mid == n)
    {
        if ((mid < nums.size() - 1 && nums[mid + 1] != n) || mid == nums.size() - 1)
        {
            return mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    else if (num_mid > n)
    {
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }

    return lastK_recursion(nums, n, low, high);
}

int count(const vector<int> nums, int n)
{
    int time = 0;
    if (nums.size() > 0)
    {
        int fk = firstK_recursion(nums, n, 0, nums.size() - 1);
        int lk = lastK_recursion(nums, n, 0, nums.size() - 1);
        if (fk > -1 && lk > -1)
            time = lk - fk + 1;
    }
    return time;
}

int main()
{
    FILE *fp = fopen("../test-data/38.txt", "r");
    int length, k, n;
    vector<int> nums;

    // 读入数据
    fscanf(fp, "%d %d\n", &length, &k);
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

    // 计算出现次数
    int time = count(nums, k);
    printf("%d的出现次数为%d\n", k, time);

    return 0;
}