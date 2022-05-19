#include <stdio.h>

int narcissistic(int number);
void PrintN(int m, int n);

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if (narcissistic(m))
        printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if (narcissistic(n))
        printf("%d is a narcissistic number\n", n);

    return 0;
}
#include <math.h>
int narcissistic(int number)
{
    int A[5] = {0}, cnt = 0, t = number, s = 0;
    while (t > 0)
        A[cnt++] = t % 10, t /= 10;
    for (int i = 0; i < cnt; i++)
        s += pow(A[i], cnt);
    return s == number ? 1 : 0;
}

void PrintN(int m, int n)
{
    for (int i = m + 1; i <= n - 1; i++)
        if (narcissistic(i))
            printf("%d\n", i);
}