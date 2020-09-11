/*
 * 圆圈中最后剩下的数字
 */
int lastRemaining(int n, int m)
{
    if (n == 1)
        return 0;
    int pos = 0;
    for (int i = 2; i <= n; i++)
        pos = (pos + m) % i;
    return pos;
}
