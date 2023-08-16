/**
 * @file    :   1858B
 * @author  :   Tanphoon
 * @date    :   2023/08/15 23:23
 * @version :   2023/08/15 23:23
 * @link    :   https://codeforces.com/contest/1858/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> p(m + 2);
    vector<ll> a(m + 2); // 区间(p[i-1], p[i]]内吃多少个
    for (int i = 1; i <= m; i++)
        cin >> p[i];
    p[0] = 1;
    a[0] = 1;
    for (int i = 1; i <= m; i++) {
        a[i] = (p[i] - p[i - 1]) / d;
        if ((p[i] - p[i - 1]) % d != 0)
            a[i]++;
    }
    p[m + 1] = n;
    a[m + 1] = (p[m + 1] - p[m]) / d;
    pair<int, int> mx;
    for (int i = 1; i <= m; i++) {
        // 计算删除每个小贩，能够少吃多少个饼干
        int s = (p[i + 1] - p[i - 1]) / d;
        if ((p[i + 1] - p[i - 1]) % d != 0 && i < m)
            s++;
        s = a[i] + a[i + 1] - s;
        if (mx.first < s)
            mx = {s, 1};
        else if (mx.first == s)
            mx.second++;
    }
    int sum = accumulate(a.begin(), a.end(), 0LL);
    cout << sum - mx.first << ' ' << mx.second << '\n';
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}