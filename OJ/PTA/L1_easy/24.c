// 7-24求偶数之和
#include <stdio.h>
int main()
{
    int s = 0;
    for (int i = 0; i <= 100; i += 2)
        s += i;
    printf("%d", s);
    return 0;
}