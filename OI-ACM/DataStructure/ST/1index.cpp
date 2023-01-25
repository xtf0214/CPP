#include <bits/stdc++.h>
using namespace std;

template <typename T, T (*op)(T, T)> struct SparseTable {
    vector<vector<T>> dat;
    SparseTable(const vector<T> &v) {
        int n = v.size(), logn = __lg(n);
        dat.assign(n + 1, vector<T>(logn + 1, 0));
        for (int i = 1; i <= n; ++i)
            dat[i][0] = v[i - 1];
        for (int j = 1; j <= logn; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                dat[i][j] = op(dat[i][j - 1], dat[i + (1 << j - 1)][j - 1]);
    }
    T query(int l, int r) {
        int s = __lg(r - l + 1);
        return op(dat[l][s], dat[r - (1 << s) + 1][s]);
    }
};
int maxn(int a, int b) { return a > b ? a : b; }
int main() {
    int n, m;
    vector<int> a;
    cin >> n >> m;
    for (int i = 0, x; i < n; i++)
        cin >> x, a.push_back(x);
    SparseTable<int, maxn> st(a);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << endl;
    }
    return 0;
}