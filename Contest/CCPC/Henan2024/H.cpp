/**
 * @file    :   H
 * @author  :   Tanphoon
 * @date    :   2024/05/15 13:13
 * @version :   2024/05/15 13:13
 * @link    :   https://codeforces.com/gym/105158/problem/H
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10, mod = 998244353;
ll ksm(ll a, ll b) {
    ll s = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            s = s * a % mod;
    return s;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    set<int> s;
    vector<int> st(N);
    int cnt = 0;
    int mn = 0;
    ll p = 1, q = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (a[i] >= 0) {
            if (a[i] < mn) {
                cout << 0 << '\n';
                return;
            }
            cnt++;
            if (++st[a[i]] == 1)
                s.insert(a[i]);
        } else {
            int cur = *s.begin();
            p = p * st[cur] % mod;
            q = q * cnt % mod;
            cnt--;
            if (--st[cur] == 0)
                s.erase(cur);
            mn = max(mn, cur);
        }
    }
    cout << p * ksm(q, mod - 2) % mod << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}