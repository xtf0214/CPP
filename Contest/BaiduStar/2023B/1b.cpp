#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> a[3];

int calc(vector<int> &v, int opt) {
    vector<int> b(v);
    sort(b.begin(), b.end());
    if (opt) {
        for (int i = 0; i < n; i++)
            b[i] -= i + 1;
        sort(b.begin(), b.end());
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(b[i] - b[n / 2]);
    return ans;
}

signed main() {
    cin >> n;
    for (int i = 0; i < 3; i++)
        a[i].resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    int ans = 0, mn = 1e18;
    for (int d = 0; d < 3; d++) {
        int cur = calc(a[d], 0);
        mn = min(mn, calc(a[d], 1) - cur);
        ans += cur;
    }
    cout << ans + mn << '\n';
}