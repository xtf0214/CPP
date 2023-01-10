#include <bits/stdc++.h>
using namespace std;
int main()
{
    int low, high, a, b, maxa, mina;
    bool a1, b1;
    cin >> low >> high >> a >> b;
    maxa = max(a, b), mina = min(a, b);
    if (maxa >= high && mina >= low)
    {
        printf("%d-Y %d-Y\n", a, b);
        printf("huan ying ru guan");
    }
    else if (maxa >= high && mina < low)
    {
        printf("%d-Y %d-Y\n", a, b);
        printf("qing %d zhao gu hao %d", maxa == a ? 1 : 2, mina == b ? 2 : 1);
    }
    else if (maxa < high && mina >= low)
    {
        if (maxa == a)
        {
            printf("%d-N %d-Y\n", a, b);
        }
        else
        {
            printf("%d-Y %d-N\n", a, b);
        }
        printf("%d: huan ying ru guan", mina == a ? 1 : 2);
    }
    else
    {
        printf("%d-N %d-N\n", a, b);
        printf("zhang da zai lai ba");
    }
    return 0;
}