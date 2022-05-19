#include <stdio.h>
int main()
{
    int n, cnt = 0;
    double score;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &score);
        if (score >= 60)
            cnt++;
    }
    printf("%.2lf", (double)cnt / n);
    return 0;
}