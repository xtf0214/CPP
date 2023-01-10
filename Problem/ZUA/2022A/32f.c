#include <stdio.h>
int main()
{
    double sum = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        sum += i % 2 ? 1.0 / (3 * i - 2) : -1.0 / (3 * i - 2);
    printf("sum = %.3lf", sum);
    return 0;
}