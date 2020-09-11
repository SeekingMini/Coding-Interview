/*
 * 旋转数组的最小数字
 */
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int Min(int *numbers, int length)
{
    if (numbers == NULL || length <= 0)
    {
        return -1;
    }
    if (length == 1)
    {
        return numbers[0];
    }

    int idx_1 = 0, idx_2 = length - 1;
    int mid = idx_1;
    while (numbers[idx_1] >= numbers[idx_2])
    {
        if (idx_2 - idx_1 == 1)
        {
            mid = idx_2;
            break;
        }

        mid = (idx_1 + idx_2) / 2;
        if (numbers[mid] >= numbers[idx_1])
        {
            idx_1 = mid;
        }
        // 顺序查找
        if (numbers[mid] == numbers[idx_1] && numbers[idx_1] == numbers[idx_2])
        {
            return *min_element(numbers, numbers + length);
        }
        else if (numbers[mid] <= numbers[idx_2])
        {
            idx_2 = mid;
        }
    }

    return numbers[mid];
}

int main()
{
    FILE *fp = fopen("../test-data/8.txt", "r");
    int length;
    fscanf(fp, "%d\n", &length);

    // 读入数据
    int *numbers = new int(length + 1);
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &numbers[i]);
    }

    // 打印数据
    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int min = Min(numbers, length);
    printf("%d\n", min);

    return 0;
}
