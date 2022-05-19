#include <stdio.h>
int main()
{
    int sum = 0;
    int n, ai = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        ai *= i;
        sum += ai;
    }
    printf("%d", sum);
    return 0;
}