#include <stdio.h>
#include <string.h>
#define MAX 10000 + 5
int isPrime[MAX];
int Prime[MAX], cnt = 0;
void eratosthenes(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
        {
            Prime[cnt++] = i;
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = 0;
        }
}
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    eratosthenes(n);
    for (int i = cnt - 1; i >= cnt - 10 && i >= 0; i--)
        printf("%d ", Prime[i]), sum += Prime[i];
    printf("\nsum = %d", sum);
    return 0;
}