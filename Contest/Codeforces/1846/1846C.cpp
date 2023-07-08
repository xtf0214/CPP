/**
 * @file    :   1846C
 * @author  :   Tanphoon
 * @date    :   2023/07/07 22:59
 * @version :   2023/07/07 22:59
 * @link    :   https://codeforces.com/contest/1846/problem/C
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<array<ll, 3>> rank(n);
    vector<vector<ll>> t(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> t[i][j];
        sort(t[i].begin(), t[i].end());
        for (int j = 0; j < m; j++) {
            if (j > 0)
                t[i][j] += t[i][j - 1];
            if (t[i][j] <= h) {
                rank[i][0]++;
                rank[i][1] += t[i][j];
            }
        }
        // print(t[i]);
        rank[i][2] = i;
    }
    sort(rank.begin(), rank.end(), [](const array<ll, 3> & a, const array<ll, 3> &b){
        if (a[0] != b[0])
            return a[0] > b[0];
        else if (a[1] != b[1])
            return a[1] < b[1];
        else return a[2] < b[2];
    });
    // for (int i = 0; i < n; i++)
    //     print(rank[i]);
    for (int i = 0; i < n; i++)
        if (rank[i][2] == 0)
            cout << i + 1 << '\n';
    // cerr << "------\n";
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}