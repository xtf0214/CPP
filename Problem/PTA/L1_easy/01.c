// 7-1 时间换算
#include <stdio.h>
int main()
{
    int n, hh, mm, ss, add;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        scanf("%d", &add);
        ss += add % 60;
        //秒位进位
        mm += ss / 60;
        ss %= 60;

        mm += add / 60 % 60;
        //分钟位进位
        hh += mm / 60;
        mm %= 60;

        hh += add / 60 / 60 % 60;
        hh %= 24;
        printf("time: %d:%d:%d\n", hh, mm, ss);
    }
    return 0;
}