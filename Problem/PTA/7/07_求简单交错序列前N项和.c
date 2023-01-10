#include <stdio.h>
int main()
{
    int n;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        double a = 1.0 / (3 * i - 2);
        a = i % 2 == 0 ? -a : a;
        sum += a;
    }
    printf("sum = %.3lf", sum);
    return 0;
}