/** 
 * @file    :   取石子
 * @author  :   Tanphoon 
 * @date    :   2023/11/13 23:49
 * @version :   2023/11/13 23:49
 * @link    :   https://ac.nowcoder.com/acm/contest/68504/H
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    puts(n & 1 ? "Alice" : "Bob");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}