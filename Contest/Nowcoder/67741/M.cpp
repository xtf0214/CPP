/** 
 * @file    :   M
 * @author  :   Tanphoon 
 * @date    :   2024/02/03 14:00
 * @version :   2024/02/03 14:00
 * @link    :   https://ac.nowcoder.com/acm/contest/67741/M
 */ 
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int ans = n / 6;
    if (n % 6)
        ans *= 2;
    cout << ans << '\n';
}
int main() {
    ios;
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}