/**
 * @file    :   G
 * @author  :   Tanphoon
 * @date    :   2023/11/13 02:48
 * @version :   2023/11/13 02:48
 * @link    :   https://codeforces.com/gym/104768/problem/G
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    string t;
    cin >> t;

    int cnt = 0;
    for (char c : t) {
        cnt += c == '(' ? 1 : -1;
        cnt = max(cnt, 0);
    }

    if (cnt == 0) {
        cout << t << "\n";
    } else {
        cout << "impossible\n";
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}