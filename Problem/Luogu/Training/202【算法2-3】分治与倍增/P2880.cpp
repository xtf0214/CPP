// P2880 [USACO07JAN] Balanced Lineup G
// https://www.luogu.com.cn/problem/P2880
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

template <typename T, T (*op)(T, T)>
struct SparseTable
{
    vector<vector<T>> dat;
    SparseTable(const vector<T> &v)
    {
        int n = v.size(), logn = __lg(n);
        dat.assign(n + 1, vector<T>(logn + 1, 0));
        for (int i = 1; i <= n; ++i)
            dat[i][0] = v[i - 1];
        for (int j = 1; j <= logn; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                dat[i][j] = op(dat[i][j - 1], dat[i + (1 << j - 1)][j - 1]);
    }
    T query(int l, int r)
    {
        int s = __lg(r - l + 1);
        return op(dat[l][s], dat[r - (1 << s) + 1][s]);
    }
};

int maxn(int a, int b) { return a > b ? a : b; }
int minn(int a, int b) { return a < b ? a : b; }
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SparseTable<int, maxn> st_max(a);
    SparseTable<int, minn> st_min(a);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << st_max.query(l, r) - st_min.query(l, r) << endl;
    }
    return 0;
}