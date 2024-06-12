/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2024/06/13 01:45
 * @version :   2024/06/13 01:45
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    ll n;
    cin >> n;
    double s = 0;
    if (n > 1e6) {
        cout << "3.14159" << '\n';
        return;
    }
    for (ll i = 1; i < n; i++)
        s += sqrt(n * n - i * i) / (n * (n - 1));
    cout << s * 4 << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}