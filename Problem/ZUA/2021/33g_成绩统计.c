#include <stdio.h>
int main()
{
    int sum = 0, max = 0, min = 100;
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        sum += a;
        max = max > a ? max : a;
        min = min < a ? min : a;
    }
    printf("%d %d %d %.2lf", sum, max, min, (double)sum / n);
    return 0;
}