#include <stdio.h>
int main()
{
    int x, a[10] = {0}, n = 0;
    scanf("%d", &x);
    while (x)
        a[n++] = x % 8, x /= 8;
    for (int i = n - 1; i >= 0; i--)
        printf("%d", a[i]);
}