#include <stdio.h>
int main()
{
    int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y, m, d, s = 0;
    scanf("%d %d %d", &y, &m, &d);
    Month[2] += (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) ? 1 : 0;
    for (int i = 0; i < m; i++)
        s += Month[i];
    s += d;
    printf("%d", s);
    return 0;
}