#include <stdio.h>
int main()
{
    int a, b, n;
    int sum[15];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        sum[i] = a + b;
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", sum[i]);
    return 0;
}