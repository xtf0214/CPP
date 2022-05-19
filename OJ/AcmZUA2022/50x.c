#include <stdio.h>
int main()
{
    int n, a, b;
    scanf("%d", &n);
    scanf("%d", &a);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &b);
        printf("%d ", b - a);
        a = b;
        if (i % 3 == 0)
            printf("\n");
    }
    return 0;
}