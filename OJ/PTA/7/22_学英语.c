#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf("%c%c\n", 'A' + a - 1, 'a' + a - 1);
    return 0;
}
