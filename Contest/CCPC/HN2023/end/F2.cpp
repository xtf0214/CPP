/**
 * @file    :   Problem F. Art for Last    ST表
 * @author  :   Tanphoon
 * @date    :   2023/05/14 16:44
 * @version :   2023/05/14 16:44
 * @link    :   https://codeforces.com/gym/104354/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> struct ST {
    int n, logn;
    vector<vector<T>> dat;
    ST(const vector<T> &v) : n(v.size()), logn(__lg(n) + 1), dat(n + 1, vector<T>(logn + 1)) {
        for (int i = 1; i <= n; i++)
            dat[i][0] = v[i - 1];
        for (int j = 1; j <= logn; j++)
            for (int i = 1; i + (1 << j) - 1<= n; i++)
                dat[i][j] = min(dat[i][j - 1], dat[i + (1 << j - 1)][j - 1]);
    }
    T query(int l, int r) {
        int s = __lg(r - l + 1);
        return min(dat[l][s], dat[r - (1 << s) + 1][s]);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1]; // query(x,y) = max[x+1,y]

    long long ans = INT64_MAX;
    ST<int> st(vector<int>(b.begin() + 1, b.end()));

    for (int i = 1, j = k; j <= n; i++, j++)
        ans = min(ans, 1LL * (a[j] - a[i]) * st.query(i + 1, j));

    cout << ans << endl;
}