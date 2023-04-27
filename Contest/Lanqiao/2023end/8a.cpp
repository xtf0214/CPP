/**
 * @file    :   8 整数删除
 * @author  :   Tanphoon
 * @date    :   2023/04/25 17:09
 * @version :   2023/04/25 21:20
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;
const int N = 5e5 + 5;

template <typename T, T (*op)(T, T), T (*e)()> class SegmentTree {
    int n;
    vector<T> dat;
    int ls(int p) { return p << 1; }
    int rs(int p) { return p << 1 | 1; }
    int bit_ceil(int n) { return 1 << 32 - __builtin_clz(n - 1); }

  public:
    SegmentTree(int len) : n(bit_ceil(len)), dat(2 * n, e()) {}
    SegmentTree(const vector<T> &v) : n(bit_ceil(v.size())), dat(2 * n, e()) {
        copy(v.begin(), v.end(), dat.begin() + n); // [1,n-1]为枝,[n,2*n-1]为叶
        for (int p = n - 1; p >= 1; p--)
            dat[p] = op(dat[ls(p)], dat[rs(p)]);
    }
    void update(int i, T k) { // 单点修改
        dat[i += n - 1] = k;
        for (int p = i >> 1; p; p >>= 1)
            dat[p] = op(dat[ls(p)], dat[rs(p)]);
    }
    T query(int a, int b) { return query(a, b, 1, 1, n); } // 区间查询[a,b]
    T query(int a, int b, int p, int l, int r) {
        if (a > r || b < l)
            return e();
        if (a <= l && b >= r)
            return dat[p];
        int m = (l + r) / 2;
        T vl = query(a, b, ls(p), l, m);
        T vr = query(a, b, rs(p), m + 1, r);
        return op(vl, vr);
    }
};

template <typename T> T Min(T a, T b) { return a < b ? a : b; }
template <typename T> T e() { return pli{INT64_MAX, 0}; }

ll a[N];
int pre[N], nxt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    SegmentTree<pli, Min, e> seg(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        seg.update(i, pli{x, i});
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    while (k--) {
        auto u = seg.query(1, n);
        ll ai = u.first;
        int i = u.second;
        a[i] = -1;
        seg.update(i, pli{INT64_MAX, i});
        int p1 = pre[i], p2 = nxt[i];
        pre[p2] = p1;
        nxt[p1] = p2;

        if (1 <= p1) {
            a[p1] += ai;
            seg.update(p1, pli{a[p1], p1});
        }
        if (p2 <= n) {
            a[p2] += ai;
            seg.update(p2, pli{a[p2], p2});
        }
    }
    for (int i = 1; i <= n; i++)
        if (a[i] != -1)
            cout << a[i] << " ";
    return 0;
}
