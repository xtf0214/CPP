#include <stdio.h>
int main()
{
    double sum = 1;
    double ai=1;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        ai /= i;
        sum += ai;
    }
    printf("%.8lf", sum);
    return 0;
}