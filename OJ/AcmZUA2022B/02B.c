// 1022 Problem  B	aabb （第一讲）
#include <stdio.h>
#include <math.h>
#define MAX 10000 + 5
int sqr(int x)
{
    double sq = sqrt(x);
    return sq == (int)sq ? 1 : 0;
}
int main()
{
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            if (sqr(i * 1000 + i * 100 + j * 10 + j))
                printf("%d\n", i * 1000 + i * 100 + j * 10 + j);
    return 0;
}