/*
 * 青蛙跳台阶(本质是个斐波那契数列问题)
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 100

int numWays(int n)
{
    if (n <= 0)
    {
        return -1;
    }
    if (n == 1)
    {
        return 1;
    }
    int fib_n = 0;
    int one = 0;
    int two = 1;
    for (int i = 2; i <= n; i++)
    {
        fib_n = one + two;
        one = two;
        two = fib_n;
    }

    return fib_n;
}

int main()
{
    FILE *fp = fopen("../test-data/9.txt", "r");
    int n;
    fscanf(fp, "%d\n", &n);

    int ways = numWays(n);
    printf("%d\n", ways);

    return 0;
}
