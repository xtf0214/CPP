#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll a = m, b = n - m;
    if (a <= b && a % b == m)
        cout << a << " " << b << '\n';
    else
        cout << -1 << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}