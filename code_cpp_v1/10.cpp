/*
 * 二进制中1的个数
 */
#include <cstdio>
using namespace std;

int countOne(int n)
{
    int count = 0;
    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }

    return count;
}

int main()
{
    FILE *fp = fopen("./10.txt", "r");
    int n;
    fscanf(fp, "%d\n", &n);

    printf("%d\n", countOne(n));

    return 0;
}