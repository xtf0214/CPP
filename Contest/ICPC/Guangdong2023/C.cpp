/** 
 * @file    :   problemC
 * @author  :   Tanphoon 
 * @date    :   2024/01/24 14:42
 * @version :   2024/01/24 14:42
 * @link    :   https://codeforces.com/gym/104369/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    vector<ll> p(n + 2), q(n + 2);
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i].second;
    for (int i = n; i >= 1; i--)
        q[i] = q[i + 1] + a[i].second;
    int pos = n + 1;
    for (int i = 1; i <= n; i++)
        if (p[i] > q[i + 1]) {
            pos = i;
            break;
        }
    pos--;
    ll pre = 0;
    for (int i = 1; i <= pos; i++)
        pre += a[i].first * a[i].second;
    ll post = 0;
    for (int i = pos + 1; i <= n; i++)
        post += a[i].first * a[i].second;
    post -= a[pos + 1].first * (q[pos + 1] - p[pos]);
    cout << post - pre << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}