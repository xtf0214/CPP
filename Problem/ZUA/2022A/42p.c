#include <stdio.h>
int main()
{
    int a[15], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int t;
    for (int *p = a, *q = a + n - 1; p <= q; p++, q--)
        t = *p, *p = *q, *q = t;
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}