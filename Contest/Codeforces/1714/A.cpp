/** 
 * @file    :   A
 * @author  :   Tanphoon 
 * @date    :   2024/01/11 21:25
 * @version :   2024/01/11 21:25
 * @link    :   https://codeforces.com/contest/1714/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
inline void solve() {
    int n;
    int H, M;
    cin >> n >> H >> M;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int h, m;
        cin >> h >> m;
        a.push_back(h * 60 + m);
    }
    sort(a.begin(), a.end());
    for (int x : a) {
        a.push_back(24 * 60 + x);
    }
    int it = *lower_bound(a.begin(), a.end(), H * 60 + M);
    it -= H * 60 + M;
    it %= 24 * 60;
    cout << it / 60 << ' ' << it % 60 << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}