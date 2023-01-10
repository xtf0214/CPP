#include <stdio.h>
int main()
{
    int year;
    scanf("%d", &year);
    if (year < 2001 || year > 2100)
    {
        printf("Invalid year!");
        return 0;
    }
    for (int i = 2001; i <= year; i++)
    {
        if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)
            printf("%d\n", i);
    }
    return 0;
}