/**
 * @file    :   Codeforces Round #835 (Div. 4) C
 * @author  :   Tanphoon 
 * @date    :   2022/11/21 22:35
 * @version :   2022/11/21 22:35
 * @link    :   https://codeforces.com/contest/1760/problem/C
*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vT = vector<T>;

template <typename T, T (*op)(T, T)>
struct SparseTable
{
    vector<vector<T>> dat;
    SparseTable(const vector<T> &v)
    {
        int n = v.size(), logn = __lg(n) + 1;
        dat = vector<vector<T>>(n + 1, vector<T>(logn + 1, 0));
        for (int i = 1; i <= n; i++)
            dat[i][0] = v[i - 1];
        for (int j = 1; j <= logn; j++)
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
void solve()
{
    int n;
    cin >> n;
    vT<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    SparseTable<int, maxn> st(s);
    cout << s[0] - st.query(2, n) << " ";
    for (int i = 2; i <= n - 1; i++)
    {
        int maxx = max(st.query(1, i - 1), st.query(i + 1, n));
        cout << s[i - 1] - maxx << " ";
    }
    cout << s[n - 1] - st.query(1, n - 1) << endl;
}
signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}