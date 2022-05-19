#include <stdio.h>
#include <math.h>
int prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return x != 1;
}
int su_sum(int *a, int m, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (prime(a[i * n + j]))
                sum += a[i * n + j];
    return sum;
}
int main()
{
    int a[3][3];
    int i, j;
    int sum;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    sum = su_sum(&a[0][0], 3, 3);
    printf("%d", sum);
    return 0;
}