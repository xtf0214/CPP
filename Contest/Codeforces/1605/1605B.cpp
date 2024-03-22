/** 
 * @file    :   1605B
 * @author  :   Tanphoon 
 * @date    :   2023/11/23 23:30
 * @version :   2023/11/23 23:30
 * @link    :   https://codeforces.com/contest/1605/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (is_sorted(s.begin(), s.end())) {
        cout << 0 << '\n';
        return;
    }
    // 0 on the left, 1 on the right
    // if not sorted, then exist x(x>0) pos in [1, cnt0] is 1, x pos in [cnt0 + 1, n], sorted this pos
    string t = s;
    sort(s.begin(), s.end());
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
            ans.push_back(i + 1);
    cout << 1 << '\n' << ans.size() << " ";
    for (int i : ans)
        cout << i << " ";
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}