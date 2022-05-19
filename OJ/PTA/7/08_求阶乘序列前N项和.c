#include <stdio.h>
long long fact(int x)
{
    long long s = 1;
    for (int i = 1; i <= x; i++)
        s *= i;
    return s;
}
int main()
{
    long long sum = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        sum += fact(i);
    printf("%ld", sum);
    return 0;
}