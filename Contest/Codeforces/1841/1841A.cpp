/** 
 * @file    :   Educational Codeforces Round 150 (Rated for Div. 2) 1841A
 * @author  :   Tanphoon 
 * @date    :   2023/06/21 17:38
 * @version :   2023/06/21 17:38
 * @link    :   https://codeforces.com/contest/1841/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    puts(n < 5 ? "Bob" : "Alice");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}