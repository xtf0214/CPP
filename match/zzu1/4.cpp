#include <bits/stdc++.h>
using namespace std;
int main()
{
    int hh1, mm1, hh2, mm2;
    int t1, t2, t0;
    scanf("%d:%d-%d:%d", &hh1, &mm1, &hh2, &mm2);
    t2 = hh2 * 60 + mm2;
    t1 = hh1 * 60 + mm1;
    scanf("%d:%d", &hh1, &mm1);
    t0 = hh1 * 60 + mm1;
    double s = 0;
    if (t0 < t1)
        s = (t2 - t1 + 1) * (t1 - t0 + t2 - t0) / 2.0 / (t2 - t1 + 1);
    else
        s = (t2 - t0 + 1) * (0 + t2 - t0) / 2.0 / (t2 - t1 + 1);
    printf("%.2lf", s);
}