#include <stdio.h>
#include <math.h>

int prime(int p);
void Goldbach(int n);

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if (prime(m) != 0)
        printf("%d is a prime number\n", m);
    if (m < 6)
        m = 6;
    if (m % 2)
        m++;
    cnt = 0;
    for (i = m; i <= n; i += 2)
    {
        Goldbach(i);
        cnt++;
        if (cnt % 5)
            printf(", ");
        else
            printf("\n");
    }

    return 0;
}

int prime(int x)
{
    if (x == 0 || x == 1)
        return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void Goldbach(int n)
{
    for (int i = 2; i < n; i++)
        if (prime(i))
            if (prime(n - i))
            {
                printf("%d=%d+%d", n, i, n - i);
                break;
            }
}