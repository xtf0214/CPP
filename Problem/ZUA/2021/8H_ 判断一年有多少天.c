#include <stdio.h>
int main()
{
    int y;
    scanf("%d", &y);
    if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
        printf("366");
    else
        printf("365");
    return 0;
}