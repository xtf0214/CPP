/** 
 * @file    :   SegmentTree fork jiangly
 * @author  :   Tanphoon 
 * @date    :   2024/04/22 11:11
 * @version :   2024/04/22 11:11
 * @link    :   https://ac.nowcoder.com/acm/contest/view-submission?submissionId=63382128
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename Info> struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_) : n(n_), info(4 << __lg(n)) {}
    SegmentTree(const vector<Info> &a) : SegmentTree(a.size()) {
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (l == r)
                return void(info[p] = a[l - 1]);
            int m = (l + r) / 2;
            build(p << 1, l, m);
            build(p << 1 | 1, m + 1, r);
            info[p] = info[p << 1] + info[p << 1 | 1];
        };
        build(1, 1, n);
    }
    void modify(int p, int l, int r, int i, const Info &v) {
        if (i < l || r < i)
            return;
        if (l == r)
            return void(info[p] = v);
        int m = (l + r) / 2;
        modify(p << 1, l, m, i, v);
        modify(p << 1 | 1, m + 1, r, i, v);
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void modify(int x, const Info &v) { modify(1, 1, n, x, v); }
    Info rangeQuery(int p, int l, int r, int a, int b) {
        if (b < l || r < a)
            return Info();
        if (a <= l && r <= b)
            return info[p];
        int m = (l + r) / 2;
        return rangeQuery(p << 1, l, m, a, b) + rangeQuery(p << 1 | 1, m + 1, r, a, b);
    }
    Info rangeQuery(int a, int b) { return rangeQuery(1, 1, n, a, b); }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegmentTree<ll> seg(a);
    while (m--) {
        int op, l, r, x, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> k;
            a[x - 1] += k;
            seg.modify(x, a[x - 1]);
        } else {
            cin >> l >> r;
            cout << seg.rangeQuery(l, r) << '\n';
        }
    }
    return 0;
}