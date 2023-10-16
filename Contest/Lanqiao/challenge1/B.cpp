/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2023/10/14 19:08
 * @version :   2023/10/14 19:08
 * @link    :   https://www.lanqiao.cn/problems/5128/learning/?contest_id=144
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string s;
        cin >> s;
        int cur = 1;
        for (char c : s)
            if (c == 'L')
                cur = cur * 2 - 1;  
            else
                cur = cur * 2;
        cout << cur << '\n';
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--)
        solve();
    return 0;
}