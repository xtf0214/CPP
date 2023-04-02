/**
 * @file    :   Codeforces Round 861 (Div. 2) 1808A
 * @author  :   Tanphoon
 * @date    :   2023/03/29 21:02
 * @version :   2023/03/29 21:02
 * @link    :   https://codeforces.com/contest/1808/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

int check(int x) {
    int mx = 0, mn = 9;
    int ans = 0;
    for (; x; x /= 10) {
        mx = max(mx, x % 10);
        mn = min(mn, x % 10);
    }
    return mx - mn;
}

int solve() {
    int l, r, ans = -1, res;
    cin >> l >> r;
    for (int i = l; i <= r && ans < 9; i++)
        if (int c = check(i); ans < c)
            ans = c, res = i;
    return res;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}