/**
 * @file    :   1806B
 * @author  :   Tanphoon
 * @date    :   2023/03/21 20:44
 * @version :   2023/03/21 20:44
 * @link    :   https://codeforces.com/contest/1806/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    int cnt[2]{0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= 1)
            cnt[x]++;
    }
    if (cnt[0] == n) // 0 0 0 -> 1
        return 1;
    else if (cnt[0] <= (n + 1) / 2) // 0 1 0 -> 0
        return 0;
    else if (cnt[0] + cnt[1] == n) // 0 0 0 0 1 -> 2
        return 2;
    else
        return 1; // 0 0 0 2 1 1 1 -> 1
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}