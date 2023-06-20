/**
 * @file    :   Codeforces Round 875 (Div. 2) D. The BOSS Can Count Pairs
 * @author  :   Tanphoon
 * @date    :   2023/06/02 00:06
 * @version :   2023/06/02 00:06
 * @link    :   https://codeforces.com/contest/1831/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

// 时间复杂度O(sqrt(n)*n)
// 对于公式 a[i]*a[j]==b[i]+b[j];
// 因为 1<=b[i]+b[j]<=2*n
// 所以 1<=a[i]*a[j]<=2*n;
// 枚举a[j] 范围就是[1,sqrt(2*n)]
// 确定了a[j],就去枚举a[i]以及b[i],算出合法的b[j](b[j]=a[i]*a[j]-b[i])
// 最后统计合法的b[j]的个数 //为了降低复杂度以及去重，可以先给数组a排个顺序
// 这样枚举a[j]以及 枚举(a[i],b[i])的时候都是有序的
// 那么这个时候，对于某个位置而言，只要统计在他之前的合法的b[j]
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i].first;
    for (int i = 0; i < n; i++)
        cin >> c[i].second;
    sort(c.begin(), c.end());
    ll ans = 0;
    for (int aj = 1; aj * aj <= 2 * n; aj++) {
        vector<int> cnt(2 * n + 5);
        for (auto &[ai, bi] : c) {
            ll bj = ai * aj - bi;
            if (1 <= bj && bj <= n)
                ans += cnt[bj];
            if (ai == aj)
                cnt[bi]++;
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}