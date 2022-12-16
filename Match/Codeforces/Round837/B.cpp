#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1, n + 1); // s[i]表示区间[i, s[i]]所以对都是朋友
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        s[x] = min(s[x], y);
    }
    // 后缀最小值
    for (int i = n - 1; i >= 1; i--)
        if (s[i] > s[i + 1])
            s[i] = s[i + 1];
    for (int i = 1; i <= n; i++)
        ans += s[i] - i;
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}