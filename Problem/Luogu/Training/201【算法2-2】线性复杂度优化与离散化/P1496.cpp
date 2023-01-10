// P1496 火烧赤壁
// https://www.luogu.com.cn/problem/P1496
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define all(v) v.begin(), v.end()

vi a, b, d, f;
int n;
ll ans;
int get(int x) { return lower_bound(all(d), x) - d.begin(); }
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a = vi(n), b = vi(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        d.push_back(a[i]);
        d.push_back(b[i]);
    }
    sort(all(d));
    d.erase(unique(all(d)), d.end());
    f = vi(d.size());
    for (int i = 0; i < n; i++)
    {
        int x = get(a[i]), y = get(b[i]);
        for (int j = x; j < y; j++)
            f[j] = 1;
    }
    for (int i = 0; i < d.size() - 1; i++)
        if (f[i])
            ans += d[i + 1] - d[i];
    cout << ans;
    return 0;
}