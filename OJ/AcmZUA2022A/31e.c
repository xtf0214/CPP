#include <stdio.h>
int is_prime[505];
void ertos(int n)
{
    for (int i = 0; i <= n; i++)
        is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = 2 * i; j <= n; j += i)
                is_prime[j] = 0;
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    ertos(n);
    int cnt = 0, sum = 0;
    for (int i = m; i <= n; i++)
        if (is_prime[i])
            cnt++, sum += i;
    printf("%d %d", cnt, sum);
    return 0;
}