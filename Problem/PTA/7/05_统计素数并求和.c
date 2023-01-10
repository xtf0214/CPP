#include <stdio.h>
int Prime(int x)
{
    if (x == 2)
        return 1;
    else if (x < 2 || x % 2 == 0)
        return 0;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return 0;
    return 1;
}
int main()
{
    int m, n, cnt = 0, sum = 0;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++)
        if (Prime(i))
        {
            cnt++;
            sum += i;
        }
    printf("%d %d", cnt, sum);
    return 0;
}