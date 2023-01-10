#include <stdio.h>
int Prime(int x)
{
    if (x == 0 || x == 1)
        return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int main()
{
    int a;
    scanf("%d", &a);
    if (Prime(a) == 1)
        printf("Yes");
    else
        printf("No");
    return 0;
}