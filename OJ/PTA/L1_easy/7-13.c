// 7-13 打妖怪
#include <stdio.h>
#include <math.h>
int main()
{
    int v, h;
    scanf("%d %d", &v, &h);
    printf("%.0lf", ceil((double)v / h));
    return 0;
}