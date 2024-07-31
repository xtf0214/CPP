/**
 * @file    :   整体二分 10/10
 * @author  :   Tanphoon
 * @date    :   2024/07/31 10:05
 * @version :   2024/07/31 10:05
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

template <typename T> struct BIT {
    int n;
    vector<T> dat;
    BIT(int n = 0) : n(n), dat(n + 1, 0) {}
    inline int lowbit(int x) { return x & -x; }
    void add(int i, T x) {
        for (assert(i > 0); i <= n; i += lowbit(i))
            dat[i] += x;
    }
    T get(int i) {
        T res = 0;
        for (i = min(i, n); i; i -= lowbit(i))
            res += dat[i];
        return res;
    }
    T rangeQuery(int l, int r) { return get(r) - get(l - 1); }
};
BIT<int> tree;

using Num = pair<int, int>; // {p,x}

struct Query {
    int l, r, k, id;
}; // 一个编号为 id, 询问 [l,r] 中第 k 小数的询问

int n, m;
int ans[N];

// a 中为给定数列中值在值域区间 [l,r] 中的数
void solve(int l, int r, vector<Num> a, vector<Query> q) {
    int m = (l + r) / 2;
    if (l == r) {
        for (int i = 0; i < q.size(); i++)
            ans[q[i].id] = l;
        return;
    }
    vector<Num> a1, a2;
    for (int i = 0; i < a.size(); i++)
        if (a[i].second <= m)
            a1.push_back(a[i]), tree.add(a[i].first, 1);
        else
            a2.push_back(a[i]);
    vector<Query> q1, q2;
    for (int i = 0; i < q.size(); i++) {
        int t = tree.rangeQuery(q[i].l, q[i].r);
        if (q[i].k <= t)
            q1.push_back(q[i]);
        else
            q[i].k -= t, q2.push_back(q[i]);
    }
    for (int i = 0; i < a1.size(); i++)
        tree.add(a1[i].first, -1);
    solve(l, m, a1, q1), solve(m + 1, r, a2, q2);
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    tree = BIT<int>(n);
    vector<Num> a;
    vector<int> b(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> b[i], d[i] = b[i];
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    int nn = d.size();
    for (int i = 0; i < n; i++) {
        int x = lower_bound(d.begin(), d.end(), b[i]) - d.begin() + 1;
        a.push_back({i + 1, x});
    }
    vector<Query> qs;
    for (int i = 1; i <= m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        qs.push_back({l, r, k, i});
    }
    solve(1, nn, a, qs);
    for (int i = 1; i <= m; i++)
        cout << d[ans[i] - 1] << '\n';
}