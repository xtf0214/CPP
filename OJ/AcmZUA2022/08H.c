#include <stdio.h>
void list(int a[], int l, int m, int n)
{
    int tmp;
    for (int i = m + 1; i <= n; i++)
        for (int j = n; j >= i; j--)
            if (a[j - 1] > a[j])
                tmp = a[j - 1], a[j - 1] = a[j], a[j] = tmp;
}
int main()
{
    int k, num[10];
    int x, y;
    for (k = 0; k < 10; k++)
        scanf("%d", &num[k]);
    scanf("%d%d", &x, &y);
    list(num, 10, x, y);
    for (k = 0; k < 10; k++)
        printf("%d ", num[k]);
    return 0;
}
