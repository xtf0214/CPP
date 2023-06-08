/**
 * @file    :   B 逆序对计数
 * @author  :   Tanphoon
 * @date    :   2023/06/05 20:44
 * @version :   2023/06/05 20:44
 * @link    :   https://ac.nowcoder.com/acm/contest/37782/B
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 6e3 + 10;
int a[N];
int f[N][N], t[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // t[i][j] : 区间[i,j]有t[i][j]个小于a[i]的数
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            t[i][j] = t[i][j - 1] + (a[i] > a[j]);
    // f[i][j] : 区间[i,j]的逆序数，f[i][j]=Σt[i][j] + t[i+1][j] + ... + t[j][j]
    for (int j = n; j >= 1; j--)
        for (int i = j - 1; i >= 1; i--)
            f[i][j] = f[i + 1][j] + t[i][j];
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int t = (r - l + 1) * (r - l) / 2;
        cout << f[1][n] - f[l][r] + t - f[l][r] << '\n';
    }
    return 0;
}