/*
 * 二维数组中的查找
 */
#include <cstdio>
using namespace std;

#define MAX 100

bool find(int matrix[MAX + 1][MAX + 1], int rows, int cols, int number)
{
    bool found = false;
    if (matrix != NULL && rows > 0 && cols > 0)
    {
        int row = rows - 1;
        int col = 0;
        /*
         * 从左下角的数字开始查找。
         * 如果number大于此数，则从此数的右方的左下角开始查找；
         * 如果number小于此数，则从此数的上方的左下角开始查找；
         * 如果number等于此数，则查找结束。
         */
        while (row > 0 && col < cols)
        {
            int n = matrix[row][col];
            if (number > n)
            {
                col++;
            }
            else if (number == n)
            {
                found = true;
                break;
            }
            else
            {
                row--;
            }
        }
    }

    return found;
}

int main()
{
    int rows, cols, number;
    int matrix[MAX + 1][MAX + 1];
    FILE *fp = fopen("../test-data/3.txt", "r");

    // 读入数据
    fscanf(fp, "%d %d %d\n", &rows, &cols, &number);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
    // 打印数据
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    bool found = find(matrix, rows, cols, number);
    if (found == true)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}