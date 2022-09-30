#include <stdio.h>
int main()
{
    int i, n, m, x = 0;
    while (scanf("%d %d", &n, &m) && n + m != 0)
    {
        double s = 0;
        x++;
        for (i = n; i <= m; i++)
        {
            s = s + 1.0 / i / i;
        }
        printf("Case %d: %.5lf\n", x, s);
    }
    return 0;
}