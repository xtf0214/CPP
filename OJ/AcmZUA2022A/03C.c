#include <stdio.h>
int Factor(int m, int n)
{
    return n == 0 ? m : Factor(n, m % n);
}
int main()
{
    int x, y, f;
    scanf("%d%d", &x, &y);
    f = Factor(x, y);
    printf("%d", f);
    return 0;
}
