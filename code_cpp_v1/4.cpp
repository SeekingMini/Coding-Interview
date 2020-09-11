/*
 * 替换空格
 */
#include <cstdio>
using namespace std;

void replace(char string[], int length)
{
    if (string == NULL && length <= 0)
    {
        return;
    }

    int old_length = 0;  // 字符串长度
    int space_count = 0; // 字符串中空格的个数
    int i = 0;

    // 计算字符串中空格的数量以及整个字符的长度
    while (string[i] != '\0')
    {
        ++old_length;
        if (string[i] == ' ')
        {
            space_count++;
        }
        i++;
    }

    int index_old = old_length;
    int new_length = old_length + (space_count * 2); // 新的长度
    int index_new = new_length;
    while (index_old != 0 && index_new > index_old)
    {
        if (string[index_old] == ' ')
        {
            string[index_new--] = '0';
            string[index_new--] = '2';
            string[index_new--] = '%';
        }
        else
        {
            string[index_new--] = string[index_old];
        }
        index_old--;
    }
}

int main()
{
    int MAX = 100;
    char string[MAX];
    FILE *fp = fopen("../test-data/4.txt", "r");

    // 读入数据
    fgets(string, 100, fp);
    printf("%s\n", string);

    replace(string, MAX);
    printf("%s\n", string);

    return 0;
}