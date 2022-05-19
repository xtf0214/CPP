#include <stdio.h>
int main()
{
    int a[10], m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &a[(j + m) % n]);
        for (int j = 0; j < n; j++)
            printf("%d ", a[j]);
        printf("\n");
    }
    return 0;
}
// 1 3
// 1 2 3
// 4 5 6
// 7 8 9