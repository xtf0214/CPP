#include <bits/stdc++.h>
using namespace std;

void solve() {
    int p, k;
    cin >> p >> k;
    if (k == 0) {
        cout << 0 << '\n';
        return; 
    }
    if (p == 1) {
        cout << 1 << '\n';
        return;
    }
    int l = 0, r = k + 1, mid;
    auto check = [&](int x) -> bool {
        int s = x;
        while (x >= p)
            s += x / p, x = x % p + x / p;
        return s < k;
    };
    while (r - l > 1) {
        check(mid = l + r >> 1) ? l = mid : r = mid;
    }     
    cout << r << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}