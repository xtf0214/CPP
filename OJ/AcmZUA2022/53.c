#include <stdio.h>
int main()
{
    int i, n, a[1000], count, max = 0, num, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }
        if (count > max)
        {
            num = a[i];

            max = count;
        }
    }
    printf("%d %d", num, max);
}
