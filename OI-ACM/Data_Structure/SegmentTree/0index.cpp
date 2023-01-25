#include <iostream>
#include <vector>
using namespace std;
template <typename T, T (*op)(T, T), T e> struct SegmentTree {
    int n;
    vector<T> dat;
    int ls(int p) { return p * 2 + 1; }
    int rs(int p) { return p * 2 + 2; }
    SegmentTree(const vector<T> &v) : n(v.size()) {
        n = 1 << (32 - __builtin_clz(n - 1));          // 补成满二叉树
        dat.assign(2 * n, e);                          // 总共需要2n-1个节点
        copy(v.begin(), v.end(), dat.begin() + n - 1); // [0,n-2]为枝,[n-1,2*n-2]为叶
        for (int p = n - 2; p >= 0; p--)
            dat[p] = op(dat[ls(p)], dat[rs(p)]);
    }
    void update(int i, T k) { // 单点修改
        dat[i += n - 1] = k;
        for (int p = (i - 1) / 2; p != -1; p = (p - 1) / 2)
            dat[p] = op(dat[ls(p)], dat[(rs(p))]);
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); } // 区间查询[a,b)
    T query(int a, int b, int p, int l, int r) {
        if (a >= r || b <= l)
            return e;
        if (a <= l && b >= r)
            return dat[p];
        int m = (l + r) / 2;
        T vl = query(a, b, ls(p), l, m);
        T vr = query(a, b, rs(p), m, r);
        return op(vl, vr);
    }
};
int _plus(int a, int b) { return a + b; }
int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 1);
    SegmentTree<int, _plus, 0> seg(arr);
    for (int i = 0; i < n; i++)
        seg.update(i, i);
    cout << seg.query(0, n) << endl;
    return 0;
}