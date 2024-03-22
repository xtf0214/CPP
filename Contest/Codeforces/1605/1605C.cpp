/**
 * @file    :   1605C
 * @author  :   Tanphoon
 * @date    :   2023/11/24 13:23
 * @version :   2023/11/24 13:23
 * @link    :   https://codeforces.com/contest/1605/problem/C
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string dict[] = {"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};
    for (auto it : dict) {
        if (s.find(it) != string::npos) {
            cout << it.size() << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}