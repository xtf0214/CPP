#include <stdio.h>
#include <math.h>
void array_sum(int *a, int *b, int *c, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            c[i * n + j] = a[i * n + j] + b[i * n + j];
}
int main()
{
    int a[2][3], b[2][3], c[2][3];
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    array_sum(&a[0][0], &b[0][0], &c[0][0], 2, 3);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}