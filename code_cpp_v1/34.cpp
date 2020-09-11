/*
 * 丑数
 */
#include <cstdio>
using namespace std;

int Min(int n1, int n2, int n3)
{
    int min = (n1 < n2) ? n1 : n2;
    min = (min < n3) ? min : n3;

    return min;
}

int uglyNumber(int idx)
{
    if (idx <= 0)
    {
        return -1;
    }

    int nums[idx + 1];
    nums[0] = 1; // 1是第1个丑数
    int nextIndex = 1;

    int *m2 = nums;
    int *m3 = nums;
    int *m5 = nums;

    while (nextIndex < idx)
    {
        int min = Min(*m2 * 2, *m3 * 3, *m5 * 5);
        nums[nextIndex] = min;

        while (*m2 * 2 <= nums[nextIndex])
            m2++;
        while (*m3 * 3 <= nums[nextIndex])
            m3++;
        while (*m5 * 5 <= nums[nextIndex])
            m5++;
        nextIndex++;
    }

    int res = nums[idx - 1];

    return res;
}

int main()
{
    FILE *fp = fopen("../test-data/34.txt", "r");
    int idx;

    // 读入数据
    fscanf(fp, "%d\n", &idx);

    // 打印结果
    printf("%d\n", uglyNumber(idx));

    return 0;
}
