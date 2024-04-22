/**
 * @file    :   LazySegmentTree
 * @author  :   Tanphoon
 * @date    :   2024/04/22 11:13
 * @version :   2024/04/22 11:13
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename Info, typename Tag> struct LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_) : n(n_), info(4 << __lg(n)), tag(4 << __lg(n)) {}
    LazySegmentTree(const vector<Info> &a) : LazySegmentTree(a.size()) {
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
    void apply(int p, int l, int r, const Tag &v) {
        info[p].apply(l, r, v);
        tag[p].apply(l, r, v);
    }
    void pushdown(int p, int l, int r) {
        int m = (l + r) / 2;
        apply(p << 1, l, m, tag[p]);
        apply(p << 1 | 1, m + 1, r, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (x < l || r < x)
            return;
        if (l == r)
            return void(info[p] = v);
        pushdown(p, l, r);
        int m = (l + r) / 2;
        modify(p << 1, l, m, x, v);
        modify(p << 1 | 1, m + 1, r, x, v);
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void modify(int x, const Info &v) { modify(1, 1, n, x, v); }
    void rangeApply(int p, int l, int r, int a, int b, const Tag &v) {
        if (b < l || r < a)
            return;
        if (a <= l && r <= b)
            return apply(p, l, r, v);
        pushdown(p, l, r);
        int m = (l + r) / 2;
        rangeApply(p << 1, l, m, a, b, v);
        rangeApply(p << 1 | 1, m + 1, r, a, b, v);
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void rangeApply(int a, int b, const Tag &v) { rangeApply(1, 1, n, a, b, v); }
    Info rangeQuery(int p, int l, int r, int a, int b) {
        if (b < l || r < a)
            return Info();
        if (a <= l && r <= b)
            return info[p];
        pushdown(p, l, r);
        int m = (l + r) / 2;
        return rangeQuery(p << 1, l, m, a, b) + rangeQuery(p << 1 | 1, m + 1, r, a, b);
    }
    Info rangeQuery(int a, int b) { return rangeQuery(1, 1, n, a, b); }
};
struct Tag {
    int x;
    void apply(int l, int r, const Tag &v) { x += v.x; }
};
struct Info {
    ll sum = 0;
    void apply(int l, int r, const Tag &v) { sum += (r - l + 1) * v.x; }
    friend Info operator+(Info a, Info b) { return Info{a.sum + b.sum}; }
};
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<Info> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].sum;
    LazySegmentTree<Info, Tag> seg(a);
    while (m--) {
        int op, l, r, d;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> d;
            seg.rangeApply(l, r, Tag{d});
        } else
            cout << seg.rangeQuery(l, r).sum << '\n';
    }
    return 0;
}