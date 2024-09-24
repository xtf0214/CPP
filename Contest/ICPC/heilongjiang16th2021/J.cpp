/**
 * @file    :   J
 * @author  :   Tanphoon
 * @date    :   2024/04/23 00:33
 * @version :   2024/04/23 00:33
 * @link    :   https://codeforces.com/gym/103107/problem/J
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios;
    int n, m;
    cin >> n >> m;
    map<int, int> mp, mpp;
    int cn = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        mp[x]++;
        mpp[y]++;
        if (mpp[y] == n)
            cn++;
    }
    int cnt = 0;
    int te = 0;
    for (auto [x, y] : mp) {
        cnt++;
        if (y == n)
            cnt--, m -= n - 1, te++;
    }
    int ans = n - cnt - te + min(cnt - cn, (cnt * (n - cn) + 1 - (m - cn * n)) / 2);
    cout << ans << endl;
    return 0;
}