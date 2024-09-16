#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ans[u]++;
        ans[v]++;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1)
            sum++;
    }
    if (n == 1) {
        cout << 1 << endl;
    } else
        cout << sum << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}