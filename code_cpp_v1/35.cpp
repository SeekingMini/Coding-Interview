/*
 * 第一个只出现一次的字符
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 100

char get(char string[])
{
    if (string == nullptr)
        return '\0';

    int hashTable[256];                      // 建立字符与其出现次数的映射
    memset(hashTable, 0, sizeof(hashTable)); // 初始化

    char *p_str = string;
    while (*p_str != '\0')
    {
        hashTable[*p_str]++;
        p_str++;
    }
    p_str = string;
    while (*p_str != '\0')
    {
        if (hashTable[*p_str] == 1)
            return *p_str;
        p_str++;
    }

    return '\0';
}

int main()
{
    FILE *fp = fopen("../test-data/35.txt", "r");
    char string[MAX + 1];

    // 读入数据
    fgets(string, MAX, fp);
    printf("%s\n", string);

    // 计算
    printf("%c\n", get(string));

    return 0;
}