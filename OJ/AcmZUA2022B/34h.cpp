// 1120 Problem  h	求最大连续子序列之和
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void solve(int n) {
    int ans = -INF, f = 0, a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        f = max(f + a, 0);
        ans = max(ans, f);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while (cin >> n && n)
        solve(n);
    return 0;
}
