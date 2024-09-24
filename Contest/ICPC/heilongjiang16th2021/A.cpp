/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2024/04/23 00:33
 * @version :   2024/04/23 00:33
 * @link    :   https://codeforces.com/gym/103107/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Info {
    int mx = 0, val = 0;
    friend Info operator+(const Info &a, const Info &b) {
        return {max(a.mx, b.mx), a.val | b.val};
    }
    friend ostream &operator<<(ostream &out, const Info &t) {
        return out << t.mx << ' ' << bitset<4>(t.val);
    }
    void apply(const Info &v) {
        mx &= v.mx;
        val &= v.val;
    }
};

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
    void rangeAnd(int p, int l, int r, int a, int b, const Info &v) {
        if (b < l || r < a)
            return;
        if ((info[p].val & v.val) == info[p].val)
            return;
        if (l == r) {
            info[p].apply(v);
            return;
        }
        int m = (l + r) / 2;
        rangeAnd(p << 1, l, m, a, b, v);
        rangeAnd(p << 1 | 1, m + 1, r, a, b, v);
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void rangeAnd(int a, int b, const Info &v) { rangeAnd(1, 1, n, a, b, v); }
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
    int n, m;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].mx;
        a[i].val = a[i].mx;
    }
    SegmentTree<Info> seg(a);
    while (m--) {
        char op[10];
        int l, r, x, v;
        cin >> op;
        if (*op == 'A') {
            cin >> l >> r >> v;
            seg.rangeAnd(l, r, {v, v});
        }
        if (*op == 'U') {
            cin >> x >> v;
            seg.modify(x, {v, v});
        }
        if (*op == 'Q') {
            cin >> l >> r;
            cout << seg.rangeQuery(l, r).mx << '\n';
        }
    }
    return 0;
}