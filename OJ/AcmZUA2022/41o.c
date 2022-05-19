#include <stdio.h>
int main()
{
    int a, n, s = 0;
    int mul = 1;
    scanf("%d %d", &a, &n);
    for (int i = 0, mul = 1; i < n; i++, mul *= 10)
        s += (n - i) * mul;
    printf("s = %d", a * s);
}