// 7-32 螺旋方阵
#include <stdio.h>
int main()
{
    int i, j, k, n, a[15][15];
    scanf("%d", &n);
    k = 1;
    for (i = 0; i < n / 2; i++) //按螺旋方阵的层数循环， n 为单数时 最后一层单独输出
    {
        for (j = i; j < n - 1 - i; j++)
            a[i][j] = k++;
        for (j = i; j < n - 1 - i; j++)
            a[j][n - 1 - i] = k++;
        for (j = n - i - 1; j > i; j--)
            a[n - i - 1][j] = k++;
        for (j = n - i - 1; j > i; j--)
            a[j][i] = k++;
    }
    if (n % 2 == 1)
        a[n / 2][n / 2] = k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d", a[i][j]);
       	printf("\n");
    }
    return 0;
}