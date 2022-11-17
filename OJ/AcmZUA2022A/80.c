#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex(char *s)
{
    char *week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int i;
    for (i = 0; i < 7; i++)
    {
        if (strcmp(week[i], s) == 0)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    char s[MAXS];

    scanf("%s", s);
    n = getindex(s);
    if (n == -1)
        printf("wrong input!\n");
    else
        printf("%d\n", n);

    return 0;
}