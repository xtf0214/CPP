#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> class SegmentTree {
    struct Node {
        int l = -1, r = -1;
        T dat = 0, tag = 0;
        friend Node operator+(const Node &a, const Node &b) {
            if (a.l == -1 || b.l == -1)
                return a.l == -1 ? b : a;
            return Node{a.l, b.r, a.dat + b.dat, 0};
        }
    };
    int n;
    vector<Node> tr;
    int bCeil(int n) { return 1 << 32 - __builtin_clz(n - 1); }
    void mark(T k, int p) {
        tr[p].dat += (tr[p].r - tr[p].l) * k;
        tr[p].tag += k;
    }
    void pushdown(int p) {
        if (tr[p].tag) {
            mark(tr[p].tag, p * 2 + 1);
            mark(tr[p].tag, p * 2 + 2);
            tr[p].tag = 0;
        }
    }

  public:
    SegmentTree(const vector<T> &v) : n(bCeil(v.size())), tr(n << 1) {
        for (int p = n - 1, i = 0; i < v.size(); i++, p++)
            tr[p].dat = v[i];
        build(0, 0, n);
    }
    void build(int p, int l, int r) {
        tr[p].l = l, tr[p].r = r;
        if (r - l > 1) {
            int m = (l + r) >> 1;
            build(p * 2 + 1, l, m);
            build(p * 2 + 2, m, r);
            tr[p] = tr[p * 2 + 1] + tr[p * 2 + 2];
        }
    }
    void update(int a, int b, T k, int p = 0) {
        if (tr[p].r <= a || b <= tr[p].l)
            return;
        if (a <= tr[p].l && tr[p].r <= b)
            return mark(k, p);
        pushdown(p);
        update(a, b, k, p * 2 + 1);
        update(a, b, k, p * 2 + 2);
        tr[p] = tr[p * 2 + 1] + tr[p * 2 + 2];
    }
    Node query(int a, int b, int p = 0) {
        if (tr[p].r <= a || b <= tr[p].l)
            return Node();
        if (a <= tr[p].l && tr[p].r <= b)
            return tr[p];
        pushdown(p);
        Node vl = query(a, b, p * 2 + 1);
        Node vr = query(a, b, p * 2 + 2);
        return vl + vr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    SegmentTree<ll> seg(arr);
    while (m--) {
        int op, l, r, d;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> d;
            seg.update(l - 1, r, d);
        } else
            cout << seg.query(l - 1, r).dat << '\n';
    }
    return 0;
}