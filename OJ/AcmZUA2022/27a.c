#include <stdio.h>
#include <math.h>
int prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return x != 1 ? 1 : 0;
}
int heshu(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (prime(a[i]) == 0)
            a[i] = 0;
}

int main()
{
    int l;
    int k, num[1000];
    scanf("%d", &l);
    for (k = 0; k < l; k++)
    {
        scanf("%d", &num[k]);
    }
    heshu(num, l);
    for (k = 0; k < l; k++)
    {
        printf("%d ", num[k]);
    }
    return 0;
}