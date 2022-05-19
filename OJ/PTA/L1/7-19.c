#include <stdio.h>
void Swap(int *x, int *y)
{
    *x = *x + *y, *y = *x - *y, *x = *x - *y;
}
int main()
{
    int a[5];
    char str[5];
    scanf("%d %d %d ", a, a + 1, a + 2);
    scanf("%s", str);
    for (int i = 1; i < 3; i++)
        for (int j = 2; j >= i; j--)
            if (a[j - 1] > a[j])
                Swap(&a[j - 1], &a[j]);
    for (int i = 0; i < 3; i++)
    {
        if (i)
            printf(" ");
        printf("%d", a[str[i] - 'A']);
    }
    return 0;
}