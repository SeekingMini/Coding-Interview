/*
 * 数值的整数次方
 */
#include <cstdio>
using namespace std;

double Power(double base, unsigned int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    else if (exponent == 1)
    {
        return base;
    }

    double res = Power(base, exponent >> 1);
    res *= res;
    if (exponent & 0x1 == 1)
    {
        res *= base;
    }

    return res;
}

int main()
{
    FILE *fp = fopen("./11.txt", "r");
    double base;
    unsigned int exponent;

    // 读入数据
    fscanf(fp, "%lf %u\n", &base, &exponent);

    // 打印结果
    double res = Power(base, exponent);
    printf("Pow(%.1f, %u) = %.1f\n", base, exponent, res);

    return 0;
}