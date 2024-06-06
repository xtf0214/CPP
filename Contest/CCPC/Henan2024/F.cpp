
/** 
 * @file    :   F
 * @author  :   Tanphoon
 * @date    :   2024/05/12 13:53
 * @version :   2024/05/12 13:53
 * @link    :   https://codeforces.com/gym/105158/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int ans = 0;
int solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    int cnt = 0;
    if (s.size() < 5)
        return 0;
    for (int i = 0; i < 4; i++)
        mp[s[i]]++;
    if (mp.size() == 4 && s[2] == s[4] && s.size() == 5)
        return 1;
    return 0;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ans += solve();
    }
    cout << ans << '\n';
}