#include <stdio.h>
#include <math.h>
int main()
{
    double x, r;
    scanf("%lf", &x);
    if (x < 0)
    {
        printf("No");
        return 0;
    }
    r = sqrt(x);
    if (r - (int)r == 0)
        printf("Yes");
    else
        printf("No");
    return 0;
}