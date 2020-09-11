/*
 * 和为s的连续正数序列
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> sequenceSum(int sum)
{
    vector<vector<int>> seqs;
    if (sum <= 2)
        return seqs;
    int start = 1;
    int end = 2;
    int limit = (sum + 1) / 2;

    while (start < limit)
    {
        int s = 0;
        for (int i = start; i <= end; i++)
            s += i;
        if (s == sum)
        {
            vector<int> seq;
            seq.push_back(start);
            seq.push_back(end);
            seqs.push_back(seq);
            start++;
            end++;
        }
        else if (s < sum)
        {
            end++;
        }
        else
        {
            start++;
        }
    }
    return seqs;
}

int main()
{
    FILE *fp = fopen("../test-data/41-2.txt", "r");
    int sum;

    // 读入数据
    fscanf(fp, "%d\n", &sum);
    printf("%d\n", sum);
    vector<vector<int>> seqs = sequenceSum(sum);
    if (!seqs.size())
    {
        printf("没有找到序列！\n");
    }
    else
    {
        for (int i = 0; i < seqs.size(); i++)
        {
            printf("%d %d\n", seqs[i][0], seqs[i][1]);
        }
    }

    return 0;
}