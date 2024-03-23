/** 
 * @file    :   1820A
 * @author  :   Tanphoon 
 * @date    :   2023/11/06 21:57
 * @version :   2023/11/06 21:57
 * @link    :   https://codeforces.com/contest/1820/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << 2 << "\n" << a - 1 << ' ' << 1 << "\n" << a << ' ' << b << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}