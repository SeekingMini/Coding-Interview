/*
 * 二叉搜索树的后序遍历序列
 */
#include <cstdio>
using namespace std;

// 判断序列seq是否为某一个二叉搜索树的后序遍历序列
bool isValidOrder(int *seq, int length)
{
    if (seq == NULL || length <= 0)
        return false;
    int root = seq[length - 1]; // 根结点是数组最后一个元素

    // 二叉搜索树中左子树所有结点值小于根结点
    int i = 0;
    for (; i < length - 1; i++)
    {
        if (seq[i] > root)
            break;
    }
    // 二叉搜索树中右子树所有结点值小于根结点
    int j = i;
    for (; j < length - 1; j++)
    {
        if (seq[j] < root)
            return false;
    }

    // 左子树递归
    bool left = true;
    if (i > 0)
        left = isValidOrder(seq, i);
    // 右子树递归
    bool right = true;
    if (i < length - 1)
        right = isValidOrder(seq + i, length - i - 1);

    return left && right;
}

int main()
{
    FILE *fp = fopen("../test-data/24.txt", "r");
    int length;

    // 读入数据
    fscanf(fp, "%d\n", &length);
    int seq[length + 1];
    for (int i = 0; i < length; i++)
    {
        fscanf(fp, "%d ", &seq[i]);
    }

    // 打印数据
    for (int i = 0; i < length; i++)
    {
        printf("%d ", seq[i]);
    }
    printf("\n");

    // 判断
    bool valid = isValidOrder(seq, length);
    if (valid == true)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}