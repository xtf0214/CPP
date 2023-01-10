#include <stdio.h>
int main()
{
    char ch;
    int k;
    if (26 > k >= 0)
        scanf("%c %d", &ch, &k);
    ch = (26 + k % 26 + ch - 'a') % 26 + 'a';
    printf("%c", ch);
    return 0;
}