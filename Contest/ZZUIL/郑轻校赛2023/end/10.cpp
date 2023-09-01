/**
 * @file    :   10 售卖车票
 * @author  :   Tanphoon
 * @date    :   2023/08/31 16:33
 * @version :   2023/08/31 16:33
 * @link    :   http://acm.zzuli.edu.cn/problem.php?id=3040
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1); // g[l]: 以l为左端点的区间的右端点 
    vector<int> cnt(n + 1); // cnt[i]: 以i为右端点的区间数
    while (m--) {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
    }
    priority_queue<int> q;
    int sum = 0, ans = 0; // sum: 点l处有sum个压力
    for (int l = 1; l <= n; l++) {
        for (int r : g[l]) {
            sum++;
            cnt[r]++;
            q.push(r);
        }
        while (sum > k) {
            cnt[q.top()]--;
            q.pop();
            sum--;
        }
        sum -= cnt[l];
        ans += cnt[l];
    }
    cout << ans << '\n';
}