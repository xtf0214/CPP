/**
 * @file    :   I
 * @author  :   Tanphoon
 * @date    :   2024/05/08 20:00
 * @version :   2024/05/08 20:00
 * @link    :   https://codeforces.com/gym/105143/problem/I
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    bool ok = 0;
    for (char i : s) {
        if (i == '0') {
            ans += ok;
            ok = 0;
        } else
            ok = 1;
    }
    cout << ans << '\n';
}