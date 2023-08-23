#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l = 0, r = 0;
    int dat = -1, id;
    friend Node operator+(const Node &a, const Node &b) {
        if (a.l == 0 || b.l == 0)
            return a.l ? a : b;
        Node c{a.l, b.r};
        tie(c.dat, c.id) = max(pair{a.dat, a.id}, pair{b.dat, b.id});
        return c;
    }
};

struct Segtree {
    int n;
    vector<Node> tr;
    void build(int u, int l, int r) {
        if (l == r) {
            tr[u].l = l, tr[u].r = r;
            return;
        } else {
            int mid = l + r >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
            tr[u] = tr[u << 1] + tr[u << 1 | 1];
        }
    }
    Segtree(int len) : n(2 << __lg(len - 1)), tr(n << 1) { build(1, 1, n); }
    void change(int i, int k, int u = 1) {
        if (tr[u].r < i || i < tr[u].l)
            return;
        if (tr[u].l == tr[u].r) {
            tr[u].dat = k;
            tr[u].id = tr[u].l;
            return;
        }
        change(i, k, u << 1);
        change(i, k, u << 1 | 1);
        tr[u] = tr[u << 1] + tr[u << 1 | 1];
    }
};
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> pv(n);
    Segtree seg(n);
    for (int i = 0; i < n; i++) {
        auto &[a, b] = pv[i];
        cin >> a >> b;
        seg.change(i + 1, b);
    }
    for (int i = 0; i < n; i++) {
        auto t = seg.tr[1];
        cout << t.dat << ' ' << t.id << '\n';
        seg.change(t.id, -1);
    }
}