/*
 * 翻转单词顺序
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 100

// 翻转字符串
void reverse(char *p_start, char *p_end)
{
    if (p_start == nullptr || p_end == nullptr)
        return;

    while (p_start < p_end)
    {
        char tmp = *p_start;
        *p_start = *p_end;
        *p_end = tmp;
        p_start++;
        p_end--;
    }
}

// 翻转所有单词
void reverseWords(char *str)
{
    if (str == nullptr)
        return;

    char *p_start = str;
    char *p_end = str;

    // 先翻转整个句子
    while (*p_end != '\0')
        p_end++;
    p_end--;
    reverse(p_start, p_end);

    // 再翻转单词
    p_start = p_end = str;
    while (*p_start != '\0')
    {
        if (*p_start == ' ')
        {
            p_start++;
            p_end++;
        }
        else if (*p_end == ' ' || *p_end == '\0')
        {
            reverse(p_start, --p_end);
            p_start = ++p_end;
        }
        else
        {
            p_end++;
        }
    }
}

int main()
{
    FILE *fp = fopen("../test-data/42-1.txt", "r");
    char str[MAX + 1];
    memset(str, 0, sizeof(str));

    // 读入数据
    fgets(str, MAX, fp);
    printf("%s\n", str);

    // 翻转
    reverseWords(str);
    printf("%s\n", str);

    return 0;
}