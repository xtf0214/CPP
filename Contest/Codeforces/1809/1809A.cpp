/**
 * @file    :   1809A
 * @author  :   Tanphoon
 * @date    :   2023/03/23 23:44
 * @version :   2023/03/23 23:44
 * @link    :   https://codeforces.com/contest/1809/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

#include "_DEBUG.h"

int solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[3]) // 1 1 1 1
        return -1;
    else if (s[0] == s[2] || s[1] == s[3]) // 1 1 1 2 或 1 2 2 2
        return 6;
    else
        return 4; // 1 1 2 2 或 1 1 2 3 或 1 2 3 4
}
int main() {
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}