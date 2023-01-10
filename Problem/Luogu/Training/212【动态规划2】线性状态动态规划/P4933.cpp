// P4933 大师
// https://www.luogu.com.cn/problem/P4933
#include <bits/stdc++.h>
using namespace std;
const int INF = 2e4 + 10, mod = 998244353;

int n, ans;
int main() {
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(INF * 2));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j < i; j++) {
            (f[i][a[i] - a[j] + INF] += f[j][a[i] - a[j] + INF] + 1) %= mod;
            (ans += f[j][a[i] - a[j] + INF] + 1) %= mod;
        }
    }
    cout << (ans + n) % mod;
    return 0;
}