/**
 * @file    :   10 售卖车票
 * @author  :   Tanphoon
 * @date    :   2023/08/31 16:33
 * @version :   2023/08/31 16:33
 * @link    :   http://acm.zzuli.edu.cn/problem.php?id=3040
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T> struct BIT {
    int size;
    vector<T> dat;
    BIT(int n = 0) : size(n), dat(n + 1, 0) {}
    inline int lowbit(int x) { return x & -x; }
    void add(int i, T x) {
        for (; i <= size; i += lowbit(i))
            dat[i] += x;
    }
    T get(int i) {
        T res = 0;
        for (; i; i -= lowbit(i))
            res += dat[i];
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    BIT<int> tr(n + 2);
    vector<vector<int>> g(n + 1); // g[l]: 以l为左端点的区间的右端点
    int ans = m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
    }
    priority_queue<pair<int, int>> q;
    for (int l = 1; l <= n; l++) {
        for (int r : g[l]) {
            tr.add(l, 1);
            tr.add(r + 1, -1);
            q.push({r, l});
        }
        int sum = tr.get(l);
        while (sum > k) {
            auto top = q.top();
            int l = top.second, r = top.first;
            q.pop();
            tr.add(l, -1);
            tr.add(r + 1, 1);
            sum--;
            ans--;
        }
    }
    cout << ans << '\n';
}