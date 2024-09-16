/**
 * @file    :   M
 * @author  :   Tanphoon
 * @date    :   2024/09/16 15:38
 * @version :   2024/09/16 15:38
 * @link    :   https://codeforces.com/gym/105139/problem/L
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getMinFactor(ll n) {
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return i;
    return n;
}
inline void solve() {
    ll a, b;
    cin >> a >> b;
    vector<ll> p{a, b, 2, getMinFactor(a), getMinFactor(b)};
    if (ll g = gcd(a, b); g != 1)
        p.push_back(g);
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size();
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
        mp[p[i]] = i;
    vector<vector<ll>> g(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            g[i][j] = g[j][i] = lcm(p[i], p[j]);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    cout << g[mp[a]][mp[b]] << '\n';

    // ll a, b;
    // cin >> a >> b;
    // int t = gcd(a, b);
    // if (a == b)
    //     cout << "0\n";
    // else if (t == a)
    //     cout << b << '\n';
    // else if (t > 1)
    //     cout << a + b << '\n';
    // else {
    //     ll ma = getMinFactor(a), mb = getMinFactor(b);
    //     cout << min({
    //                 a + 2 * ma + 2 * mb + b, // a ma 2 mb b
    //                 a + ma * 2 + b * 2,      // a ma 2 b
    //                 a * 2 + 2 * mb + b,      // a 2 mb b
    //                 a + b + ma * mb,         // a ma mb b
    //                 a + ma * b,              // a ma b
    //                 b + mb * a,              // a mb b
    //                 a * 2 + b * 2,           // a 2 b
    //                 a * b,                   // a b
    //             })
    //          << '\n';
    // }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}