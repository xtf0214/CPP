#include <stdio.h>
int fib(int n);
void PrintFN(int m, int n);

int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}
int Fib[100];
int fib(int n)
{
    if (n == 1 || n == 2)
        return Fib[n] = 1;
    else
        return Fib[n] == 0 ? Fib[n] = fib(n - 1) + fib(n - 2) : Fib[n];
}
void PrintFN(int m, int n)
{
    int cnt = 0;
    for (int i = 1;; i++)
    {
        int t = fib(i);
        if (t >= m && t <= n)
        {
            if (cnt == 0)
                printf("%d", t), cnt++;
            else
                printf(" %d", t), cnt++;
        }
        if (t > n)
            break;
    }
    if (cnt == 0)
        printf("No Fibonacci number");
}
