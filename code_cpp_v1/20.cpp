/*
 * 顺时针打印矩阵
 */
#include <cstdio>
using namespace std;

#define MAX 100

void blockWisePrint()
{
}

int main()
{
    FILE *fp = fopen("../test-data/20.txt", "r");
    int rows, columns;

    // 读入数据
    fscanf(fp, "%d %d\n", &rows, &columns);
    int matrix[rows][columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = i * columns + (j + 1);
        }
    }

    // 打印数据
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}