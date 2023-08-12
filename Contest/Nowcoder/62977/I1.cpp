#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    map<array<int, 2>, int> cnt;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int g = gcd(a[i], b[i]);
        ans += cnt[{b[i] / g, a[i] / g}];
        ++cnt[{a[i] / g, b[i] / g}];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
