/** 
 * @file    :   Codeforces Round #838 (Div. 2) A
 * @author  :   Tanphoon 
 * @date    :   2022/12/15 22:35
 * @version :   2022/12/15 22:35
 * @link    :   https://codeforces.com/contest/1762/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, s, ans = 1e9;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s ^= x;
        ans = min(ans, __builtin_ctz(x & 1 ? ~x : x));
    }
    return s & 1 ? ans : 0;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}