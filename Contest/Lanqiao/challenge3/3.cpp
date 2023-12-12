/** 
 * @file    :   3
 * @author  :   Tanphoon 
 * @date    :   2023/12/11 22:05
 * @version :   2023/12/11 22:05
 * @link    :   https://www.lanqiao.cn/problems/6278/learning/?contest_id=146
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    string a, b;
    cin >> a >> b;
    if (a[0] == a[1] || a == "MF" || a == "FM") {
        cout << "ShallowDream" << '\n';
        return;
    }
    string ss = "3456789XJQKA2MF";
    map<char, int> value;
    for (int i = 0; i < ss.size(); i++) 
        value[ss[i]] = i;
    int mxb = max(value[b[0]], value[b[1]]);
    int mxa = max(value[a[0]], value[a[1]]);
    if (b == "MF" || b == "FM" || mxb > mxa) {
        cout << "Joker" << '\n';
    } else {
        cout << "ShallowDream" << '\n';
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