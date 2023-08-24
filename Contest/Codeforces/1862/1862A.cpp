/**
 * @file    :   1862A
 * @author  :   Tanphoon
 * @date    :   2023/08/24 22:36
 * @version :   2023/08/24 22:36
 * @link    :   https://codeforces.com/contest/1862/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(m, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[j][i];
    int st = 0;
    int cnt = 0;
    char t[10] = "vika";
    while (st < m && cnt < 4) {
        int i = st;
        for (; i < m; i++) {
            if (find(a[i].begin(), a[i].end(), t[cnt]) != a[i].end()) {
                st = i + 1;
                cnt++;
                break;
            }
        }
        if (i == m)
            break;
    }
    cout << (cnt == 4 ? "YES" : "NO") << endl;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}