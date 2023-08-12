/**
 * @file    :   G
 * @author  :   Tanphoon
 * @date    :   2023/08/11 00:08
 * @version :   2023/08/11 00:08
 * @link    :   https://ac.nowcoder.com/acm/contest/62977/G
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5;

void solve() {
    int n;
    cin >> n;
    n++;
    if (n & (n - 1) == 0)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}