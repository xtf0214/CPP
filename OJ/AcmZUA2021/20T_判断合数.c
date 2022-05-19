#include <stdio.h>
int Prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int main()
{
    int a;
    scanf("%d", &a);
    if (a == 1)
    {
        printf("No");
        return 0;
    }
    if (Prime(a) == 1)
        printf("No");
    else
        printf("Yes");
    return 0;
}