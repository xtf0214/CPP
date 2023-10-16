/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/10/14 19:02
 * @version :   2023/10/14 19:02
 * @link    :   https://www.lanqiao.cn/problems/5127/learning/?contest_id=144
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c : s)
        mp[c]++;
    if (mp.size() == 2)
        if (mp.begin()->second == 3 || mp.rbegin()->second == 3) {
            cout << "Yes\n";
            return;
        }
    cout << "No\n";
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}