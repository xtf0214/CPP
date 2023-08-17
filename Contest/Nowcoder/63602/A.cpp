/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/08/16 23:44
 * @version :   2023/08/16 23:44
 * @link    :   https://ac.nowcoder.com/acm/contest/63602/A
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int s[N][32]; // s[i][j]: 前i个数字的第j位，总共有多少个1
int n, q;
int query(int l, int r) {
    int res = INT_MAX;
    for (int i = 0; i < 32; ++i) {
        if ((s[r][i] - s[l - 1][i]) * 2 >= r - l + 1) {
            res -= 1 << i;
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 32; ++j) {
            s[i][j] = s[i - 1][j] + (a[i] >> j & 1);
        }
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    return 0;
}