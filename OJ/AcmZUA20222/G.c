#include <stdio.h>
int main()
{
    int s = 0;
    for (int a = 1, b = 6; a < b; a += 2)
        s = s + a;
    printf("%d\n", s);
}