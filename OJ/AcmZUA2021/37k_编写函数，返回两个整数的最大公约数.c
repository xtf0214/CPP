#include <stdio.h>
int Factor(int m, int n)
{
    return n > 0 ? Factor(n, m % n) : m;
}
int main()
{
    int x, y, f;
    scanf("%d%d", &x, &y);
    f = x > y ? Factor(x, y) : Factor(y, x);
    printf("%d", f);
    return 0;
}