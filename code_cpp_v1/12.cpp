/*
 * 打印1到最大的n位数
 */
#include <cstdio>
#include <cstring>
using namespace std;

void printNumber(char *number)
{
    int length = strlen(number);
    bool begin_with_zero = true;

    for (int i = 0; i < length; i++)
    {
        // 忽略用来补齐的'0'
        if (begin_with_zero && number[i] != '0')
            begin_with_zero = false;
        if (!begin_with_zero)
            printf("%c", number[i]);
    }
    printf("\t");
}

