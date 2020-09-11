/*
 * 调整数组顺序使奇数位于偶数前面
 */
#include <cstdio>
#include <cstring>
using namespace std;

void swap(int *nums, int length)
{
    if (nums == NULL || length <= 0)
    {
        return;
    }

    int *p_begin = nums;            // 指向数组第1个元素
    int *p_end = nums + length - 1; // 指向数组最后1个元素
    int t1, t2;

    while (p_begin < p_end)
    {
        // 前奇后偶
        if (*p_begin % 2 == 1 && *p_end % 2 == 0)
        {
            p_begin++;
            p_end--;
        }
        // 前奇后奇
        else if (*p_begin % 2 == 1 && *p_end % 2 == 1)
        {
            p_begin++;
            t1 = *p_begin;
            t2 = *p_end;
            *p_begin = t2;
            *p_end = t1;
        }
        // 前偶后奇
        else if (*p_begin % 2 == 0 && *p_end % 2 == 1)
        {
            t1 = *p_begin;
            t2 = *p_end;
            *p_begin = t2;
            *p_end = t1;
            p_begin++;
            p_end--;
        }
        // 前偶后偶
        else if (*p_begin % 2 == 0 && *p_end % 2 == 0)
        {
            p_end--;
            t1 = *p_begin;
            t2 = *p_end;
            *p_begin = t2;
            *p_end = t1;
        }
    }
}

int main()
{
    FILE *fp = fopen("./14.txt", "r");
    int length;
    int nums[101];
    memset(nums, 0, sizeof(nums));

    // 读入数据
    fscanf(fp, "%d\n", &length);
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &nums[i]);
    }

    // 打印数据
    for (int i = 0; i < length; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    swap(nums, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}