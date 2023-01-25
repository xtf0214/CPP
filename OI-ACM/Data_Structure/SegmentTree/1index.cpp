#include <iostream>
#include <vector>
using namespace std;
template <typename T, T (*op)(T, T), T e> struct SegmentTree {
    int n;
    vector<T> dat;
    int ls(int p) { return p << 1; }
    int rs(int p) { return p << 1 | 1; }
    SegmentTree(const vector<T> &v) : n(v.size()) {
        n = 1 << (32 - __builtin_clz(n - 1));      // 补成满二叉树
        dat.assign(2 * n, e);                      // 总共需要2n-1个节点
        copy(v.begin(), v.end(), dat.begin() + n); // [1,n-1]为枝,[n,2*n-1]为叶
        for (int p = n - 1; p >= 1; p--)
            dat[p] = op(dat[ls(p)], dat[rs(p)]);
    }
    void update(int i, T k) { // 单点修改
        dat[i += n - 1] = k;
        for (int p = i >> 1; p; p >>= 1)
            dat[p] = op(dat[ls(p)], dat[(rs(p))]);
    }
    T query(int a, int b) { return query(a, b, 1, 1, n); } // 区间查询[a,b]
    T query(int a, int b, int p, int l, int r) {
        if (a > r || b < l)
            return e;
        if (a <= l && b >= r)
            return dat[p];
        int m = (l + r) / 2;
        T vl = query(a, b, ls(p), l, m);
        T vr = query(a, b, rs(p), m + 1, r);
        return op(vl, vr);
    }
};
int _plus(int a, int b) { return a + b; }
int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 1);
    SegmentTree<int, _plus, 0> seg(arr);
    for (int i = 1; i <= n; i++)
        seg.update(i, i);
    cout << seg.query(1, n) << endl;
    return 0;
}