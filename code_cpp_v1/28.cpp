/*
 * 字符串的排列
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 100

void permutation(char *str)
{
    if (str == nullptr)
        return;
    recursion(str, str);
}

void recursion(char *str, char *begin)
{
    
}

int main()
{
    FILE *fp = fopen("../test-data/28.txt", "r");
    char str[MAX + 1];
    memset(str, '\0', sizeof(str));

    // 读入字符串并打印
    fgets(str, 100, fp);
    printf("%s\n", str);

    return 0;
}