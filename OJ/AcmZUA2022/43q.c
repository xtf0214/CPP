#include <stdio.h>
void Swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
int main()
{
    int a[15], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int maxa = 0, mina = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[maxa] < a[i])
            maxa = i;
        if (a[mina] > a[i])
            mina = i;
    }
    Swap(a + n - 1, a + maxa);
    Swap(a, a + mina);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}