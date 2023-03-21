/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/03/21 20:20
 * @version :   2023/03/21 20:20
 * @link    :   https://codeforces.com/contest/1806/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int m = c - a, n = d - b;
    int x = n - m, y = n;
    if (x >= 0 && y >= 0)
        return x + y;
    else
        return -1;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}