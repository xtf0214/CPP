#include <stdio.h> //类比于L1-003
#include <string.h>
int main()
{
    double er = 1.0;
    char a[55];
    gets(a);
    int i, count = 0;
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] == '2') //使用字符'2'，因为是字符数组
            count++;
    }
    int u = strlen(a);
    if (a[0] == '-')
    {
        u = u - 1;
        er = er * 1.5;
    }
    if (a[u] % 2 == 0)
        er = er * 2.0;
    er = 100 * er * count / u;
    printf("%.2lf\%\n", er);
    return 0;
}