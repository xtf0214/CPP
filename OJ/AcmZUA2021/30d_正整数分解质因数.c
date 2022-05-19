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
    int x;
    scanf("%d", &x);
    printf("%d=", x);
    for (int i = 2;; i++)
        if (Prime(i))
            for (; x % i == 0; x /= i)
            {
                if (x == i)
                {
                    printf("%d", i);
                    return 0;
                }
                else
                    printf("%d*", i);
            }
}