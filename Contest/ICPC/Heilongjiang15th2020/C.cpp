#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#include <DEBUG.h>
using PII = pair<int, int>;
const int mod = 1e9 + 7, P = 131, N = 8e5 + 10;
int p[N], h[N];
int q(int l, int r) { return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod; }
void solve() {
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = p[i - 1] * P % mod;
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++)
        h[i] = (h[i - 1] * P % mod + s[i] - 'A' + 1) % mod;
    for (int len = 1;; len++) {
        string a, b;
        a = s.substr(1, len);
        int i, codeB = -1, ok = 0;
        int codeA = q(1, len);
        for (i = 1; i + len - 1 <= n; i += len) {
            int cur = q(i, i + len - 1);
            if (codeA == cur) {
                if (codeB != -1)
                    ok = 1;
            } else {
                if (ok)
                    break;
                if (codeB != -1 && codeB != cur) {
                    break;
                } else {
                    codeB = cur;
                    b = s.substr(i, len);
                }
            }
        }
        if (i == n + 1) {
            cout << a << ' ' << b << '\n';
            return;
        } else if (i + len > n) {
            int t = q(1, 1 + n - i);
            int _t = q(i, n);
            if (t == _t) {
                cout << a << ' ' << b << '\n';
                return;
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}