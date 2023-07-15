/**
 * @file    :   h 兴奋值
 * @author  :   Tanphoon
 * @date    :   2023/05/17 23:30
 * @version :   2023/05/17 23:30
 * @link    :   https://ac.nowcoder.com/acm/contest/37160/H
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;

template <typename T> struct ST {
    int n, logn;
    vector<vector<T>> dat;
    ST(const vector<T> &v = {}) : n(v.size()), logn(__lg(n) + 1), dat(n + 1, vector<T>(logn + 1)) {
        for (int j = 0; j <= logn; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                dat[i][j] = j ? max(dat[i][j - 1], dat[i + (1 << j - 1)][j - 1]) : v[i - 1];
    }
    T query(int l, int r) {
        int s = __lg(r - l + 1);
        return max(dat[l][s], dat[r - (1 << s) + 1][s]);
    }
};
int a[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ST<int> st(vector<int>(a + 1, a + 1 + n));
    while (m--) {
        int a, b;
        cin >> a >> b;
        int l = 0, r = (b - a + 1) + 1, m;
        auto check = [&](int m) { return st.query(a + m - 1, b) >= m; };
        while (r - l > 1)
            check(m = (l + r) / 2) ? l = m : r = m;
        cout << l << " ";
    }
    return 0;
}
/*
            l r
      0[1 2 3 4 5]6
2 3 2 8 2 4 1 2 9 4
对于[a, a+l-1]有max[a, a+l-1]>=l,最大贡献为l
对于[a+r-1, b]有max[a+r-1, b]< r,最大贡献小于r
找出最大的l,即为ans
 */