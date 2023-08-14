#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), nxt(n + 1), f(n + 1, 1e9);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nxt[mp[a[i]]] = i;
        mp[a[i]] = i;
    }
    f[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (i - 1 >= 1)
            f[i - 1] = min(f[i - 1], f[i] + 1);
        if (i + 1 <= n)
            f[i + 1] = min(f[i + 1], f[i] + 1);
        if (nxt[i])
            f[nxt[i]] = min(f[nxt[i]], f[i] + 1);
    }
    // print(f);
    cout << f[n] << '\n';
}