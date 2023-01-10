#include <stdio.h>
#include <math.h>
int main()
{
    float a, b;
    scanf("%f %f", &a, &b);
    printf("%.0f", floor(a / b));
    return 0;
}