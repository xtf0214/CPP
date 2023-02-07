/**
 * @file    :   L
 * @author  :   Tanphoon
 * @date    :   2023/01/30 16:07
 * @version :   2023/01/30 16:07
 * @link    :   https://ac.nowcoder.com/acm/contest/46812/L
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int va, vb, vc, a, b, c;
    cin >> va >> vb >> vc;
    a = vb + vc - va;
    b = va + vc - vb;
    c = va + vb - vc;
    if ((a & 1) || (b & 1) || (c & 1))
        cout << "No\n";
    else if (a < 0 || b < 0 || c < 0)
        cout << "No\n";
    else {
        a /= 2, b /= 2, c /= 2;
        if (2 * max({a, b, c}) < a + b + c) {
            cout << "Yes\n";
            cout << a << " " << b << " " << c << "\n";
        } else
            cout << "No\n";
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
