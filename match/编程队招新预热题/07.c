#include <stdio.h>
#include <math.h>
int main()
{
    char c;
    int s, n;
    scanf("%d %c", &s, &c);
    n = sqrt((s + 1) / 2);
    for (int i = n; i >= -n; i--)
    {
        if (i == 0)
        {
            i = -1;
            continue;
        }
        for (int j = abs(i); j < n; j++)
            printf(" ");
        for (int j = 0; j < 2 * abs(i) - 1; j++)
            printf("%c", c);
        printf("\n");
    }
    printf("%d", s - 2 * n * n + 1);
    return 0;
}