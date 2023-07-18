/**
 * @file    :   1797A
 * @author  :   Tanphoon
 * @date    :   2023/07/18 23:48
 * @version :   2023/07/18 23:48
 * @link    :   https://codeforces.com/contest/1797/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int solve() {
    int n, m;
    cin >> n >> m;
    pii a, b;
    cin >> a.second >> a.first >> b.second >> b.first;
    auto f = [n, m](pii a) -> int {
        if ((a.first == 1 || a.first == n) && (a.second == 1 || a.second == m))
            return 2;
        else if ((a.first == 1 || a.first == n) || (a.second == 1 || a.second == m))
            return 3;
        else
            return 4;
    };
    return min(f(a), f(b));
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << '\n';
    return 0;
}