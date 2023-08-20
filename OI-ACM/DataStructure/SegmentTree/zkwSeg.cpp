#include <bits/stdc++.h>
using namespace std;

template <typename T, T (*op)(T, T), T (*e)()> class SegmentTree {
    int n;
    vector<T> dat;

  public:
    SegmentTree(const int _n) : n(2 << __lg(_n - 1)), dat(n << 1, e()) {}
    SegmentTree(const vector<T> &v) : n(2 << __lg(v.size() - 1)), dat(n << 1, e()) {
        copy(v.begin(), v.end(), dat.begin() + n);
        for (int p = n - 1; p; p--)
            dat[p] = op(dat[p << 1], dat[p << 1 | 1]);
    }
    void update(int i, T k) { // update[i]=k
        for (dat[i += n] = k; i; i >>= 1)
            dat[i >> 1] = op(dat[i], dat[i ^ 1]);
    }
    T query(int i, int j) { // query[i,j]
        T res = e();
        for (i += n, j += n; i <= j; i >>= 1, j >>= 1) {
            res = i & 1 ? op(res, dat[i++]) : res;
            res = j & 1 ? res : op(res, dat[j--]);
        }
        return res;
    }
};
template <typename T> T Add(T a, T b) { return a + b; }
template <typename T> T e() { return 0; }
int main() {
    vector<int> a{1, 2, 3, 4, 5, 6};
    SegmentTree<int, Add, e> seg(a);
    cout << seg.query(0, 0) << endl;
    cout << seg.query(0, 1) << endl;
    cout << seg.query(0, 2) << endl;
    cout << seg.query(0, 3) << endl;
    cout << seg.query(0, 4) << endl;
    cout << seg.query(0, 5) << endl;
    return 0;
}