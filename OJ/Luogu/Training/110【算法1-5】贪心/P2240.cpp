// P2240 部分背包问题
// https://www.luogu.com.cn/problem/P2240
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define m first
#define v second
signed main() {
    int n, T;
    double ans = 0;
    cin >> n >> T;
    vector<pii> a(n);
    for (auto &[m, v] : a)
        cin >> m >> v;
    sort(a.begin(), a.end(), [](const pii &a, const pii &b) {
        // return a.v / a.m > b.v / b.m;
        return a.v * b.m > b.v * a.m;
    });
    for (auto &[m, v] : a) {
        if (T < m) {
            ans += 1.0 * T / m * v;
            break;
        }
        T -= m;
        ans += v;
    }
    printf("%.2lf", ans);
    return 0;
}
