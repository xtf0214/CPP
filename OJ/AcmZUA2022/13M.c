#include <stdio.h>
int oddarray_sum(int *a, int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i % 2 == 1)
                sum += a[i * n + j];
    return sum;
}
int main()
{
    int a[3][3];
    int i, j;
    int sum;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    sum = oddarray_sum(&a[0][0], 3, 3);
    printf("%d", sum);
    return 0;
}