#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char s[100];
    scanf("%d\n", &n);
    while (n--)
    {
        scanf("%s", s);
        int len = strlen(s);
        int num = 1;
        int max = 0;
        char maxc;
        for (int i = 1; i <= len; ++i)
        {
            if (i == len || s[i] != s[i - 1])
            {
                if (num > max)
                {
                    max = num;
                    maxc = s[i - 1];
                }
                num = 1;
            }
            else if (s[i] == s[i - 1])
                num++;
        }
        printf("%c %d\n", maxc, max);
    }
    return 0;
}