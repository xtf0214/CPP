#include <stdio.h>
int runYear(int x)
{
    if (x % 400 == 0 || x % 4 == 0 && x % 100 != 0)
        return 1;
    else
        return 0;
}
int main()
{
    int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y, m, d, s = 0;
    char A[15];
    scanf("%s", A);
    y = (A[0] - '0') * 1000 + (A[1] - '0') * 100 + (A[2] - '0') * 10 + (A[3] - '0');
    m = (A[5] - '0') * 10 + (A[6] - '0');
    d = (A[8] - '0') * 10 + (A[9] - '0');
    Month[2] += runYear(y);
    for (int i = 1; i < m; i++)
        s += Month[i];
    s += d;
    printf("%d", s);
    return 0;
}