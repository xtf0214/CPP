#include <stdio.h>
int main()
{
    int n, a, b;
    char s[10], ch;
    scanf("%s", s);
    for (int i = 0; i < 4; i++)
        s[i] = (s[i] - '0' + 9) % 10 + '0';
    ch = s[2], s[2] = s[0], s[0] = ch;
    ch = s[1], s[1] = s[3], s[3] = ch;
    printf("The encrypted number is %s", s);
    return 0;
}