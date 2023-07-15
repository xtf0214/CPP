/** 
 * @file    :   C 最大公因数
 * @author  :   Tanphoon 
 * @date    :   2023/06/16 20:52
 * @version :   2023/06/16 20:52
 * @link    :   https://ac.nowcoder.com/acm/contest/38487/C
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, x;
    cin >> a >> b >> x;
    if (a > b)
        swap(a, b);
    if (b - a < x) {
        cout << -1 << '\n';
        return;
    }
    if (a % x != 0)
        a = (a / x + 1) * x;
    if (a + x > b) {
        cout << -1 << '\n';
        return;
    }
    cout << a << " " << a + x << '\n';
}
int main() {
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}