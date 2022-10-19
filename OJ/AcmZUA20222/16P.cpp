// 1032 Problem  P	用分治法寻找最大和最小值（第三讲）
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second
pii mElement(int a[], int l, int r)
{
    if (r - l <= 1)
        return {a[l], a[l]};
    int m = (l + r) / 2;
    pii ml = mElement(a, l, m);
    pii mr = mElement(a, m, r);
    return {max(ml.fi, mr.fi), min(ml.se, mr.se)};
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pii ans = mElement(a, 0, n);
    cout << ans.fi << " " << ans.se << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
