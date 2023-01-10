#include <bits/stdc++.h>
using namespace std;
using ll = long long;


signed main()
{
    int hh, mm, ss;
    int u1, i1, u2, i2;
    int t1, t2;
    int n;
    ll res = 0;
    scanf("%d", &n);
    scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &u2, &i2);
    t2 = hh * 3600 + mm * 60 + ss;
    for (int i = 1; i < n; i++)
    {
        t1 = t2;
        u1 = u2, i1 = i2;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &u2, &i2);
        t2 = hh * 3600 + mm * 60 + ss;
        res += (t2 - t1) * u1 * i1;
    }
    cout << res << endl;
    return 0;
}