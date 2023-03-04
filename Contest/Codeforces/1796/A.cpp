/**
 * @file    :   Educational Codeforces Round 144 (Rated for Div. 2) A
 * @author  :   Tanphoon
 * @date    :   2023/02/28 22:39
 * @version :   2023/02/28 22:39
 * @link    :   https://codeforces.com/contest/1796/A
 */
#include <bits/stdc++.h>
using namespace std;

string stds = "FBFFBFFBFBFFBFFBFBFFBFFB";
bool solve() {
    string s;
    int k;
    cin >> k;
    cin >> s;
    for (int i = 0; i < 8; i++)
        if (stds.substr(i, k) == s)
            return true;
    return false;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        puts(solve() ? "YES" : "NO");
    return 0;
}