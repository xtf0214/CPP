/**
 * @file    :   1816A
 * @author  :   Tanphoon
 * @date    :   2023/11/06 11:25
 * @version :   2023/11/06 11:25
 * @link    :   https://codeforces.com/contest/1816/problem/A
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