/**
 * @file    :   I
 * @author  :   Tanphoon
 * @date    :   2023/08/09 16:48
 * @version :   2023/08/09 16:48
 * @link    :   https://ac.nowcoder.com/acm/contest/62977/I
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto &[a, b] : v)
        cin >> a;
    for (auto &[a, b] : v)
        cin >> b;
    map<pii, int> c, d;
    for (int i = 0; i < n; i++) {
        auto [a, b] = v[i];
        int g = gcd(a, b);
        a /= g, b /= g;
        c[{a, b}]++;
        d[{b, a}]++;
    }
    ll ans = 0;
    map<pii, int> st;
    for (auto &[t, cnt] : c)
        if (t.first != t.second)
            ans += cnt * d[t];
        else
            ans += cnt * (d[t] - 1);
    cout << ans / 2 << '\n';
    /*
    a b a b a
    b a b a b

    a 3 * 2 = 6
    b 2 * 3 = 6
    只计算a或者只计算b或者计算a和b然后除以2
     */
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}