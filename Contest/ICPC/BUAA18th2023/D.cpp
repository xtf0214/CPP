#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    if (m < n - 1 || m > n * (n - 1) / 2) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (i * (i + 1) / 2 <= m && (m - i * (i + 1) / 2) >= n - i - 1) {
            l = max(l, i);
        }
    }
    int restn = n - (l + 1);
    int restm = (m - l * (l + 1) / 2);
    for (int i = 2; i <= l + 1; i++)
        cout << i - 1 << ' ' << i << '\n';
    int ave = restm / restn;
    vector<int> a(n + 1, ave + 1);
    for (int i = l + 2; i <= n; i++) {
        a[i] = ave;
    }
    for (int i = l + 2; i <= l + 2 + restm % restn - 1; i++) {
        a[i]++;
    }
    for (int i = l + 2; i <= n; i++) {
        cout << i << ' ' << a[i] << '\n';
    }
    cout << 1 << '\n';
}