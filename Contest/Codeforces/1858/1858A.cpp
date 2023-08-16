/**
 * @file    :
 * @author  :   Tanphoon
 * @date    :   2023/08/15 22:40
 * @version :   2023/08/15 22:40
 * @link    :   https://codeforces.com/contest/1858/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    bool first = a > b || (a == b && c & 1);
    puts(first ? "First" : "Second");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}