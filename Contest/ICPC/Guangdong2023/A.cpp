/** 
 * @file    :   problemA
 * @author  :   Tanphoon 
 * @date    :   2024/01/24 14:32
 * @version :   2024/01/24 14:32
 * @link    :   https://codeforces.com/gym/104369/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int y1, y2, n;
    cin >> y1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> y2;
    int s = y2 - y1 + 1;
    for (int x : a) 
        if (y1 <= x && x <= y2)
            s--;
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}