#include <stdio.h>
#include <string.h>
const int MAX = 10000 + 5;
int main()
{
    int a = 0;
    for (int i = 0; i <= 1 << 7; i++)
    {
        memset(&a, i, sizeof(a));
        printf("0x%x : %d\n", a, a);
    }
    memset(&a, 1, sizeof(a));
    printf("%d : %d\n", 128, a);
    return 0;
}