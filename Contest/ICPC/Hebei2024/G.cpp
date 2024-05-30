/** 
 * @file    :   G
 * @author  :   Tanphoon 
 * @date    :   2024/05/29 02:56
 * @version :   2024/05/29 02:56
 * @link    :   https://codeforces.com/gym/105184/problem/G
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> b(3);
    cin >> b[0] >> b[1] >> b[2];
    string s1, s2;
    cin >> s1;
    int _n = s1.size();
    s2 = s1.substr(1) + s1[0];
    s1 += s1;
    s2 += s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    vector<array<int, 3>> p1(_n * 2 + 1), p2(_n * 2 + 1);
    for (int i = 2; i <= 2 * _n; i += 2) {
        p1[i] = p1[i - 2];
        int te = s1[i - 1] - '0' + s1[i] - '0';
        p1[i][te] += 1;
    }
    for (int i = 2; i <= 2 * _n; i += 2) {
        p2[i] = p2[i - 2];
        int te = s2[i - 1] - '0' + s2[i] - '0';
        p2[i][te] += 1;
    }
    auto check = [&](int len, int t = 0) {
        len *= 2;
        for (int l = 1, r = l + len - 1; l <= _n; l += 2, r += 2) {
            vector<int> res(3);
            bool ok;
            for (int t = 0; t < 3; t++)
                res[t] = p1[r][t] - p1[l - 1][t];
            ok = true;
            for (int i = 0; i < 3; i++)
                ok &= (res[i] <= b[i]);
            if (ok)
                return true;
            for (int t = 0; t < 3; t++)
                res[t] = p2[r][t] - p2[l - 1][t];
            ok = true;
            for (int i = 0; i < 3; i++)
                ok &= (res[i] <= b[i]);
            if (ok)
                return true;
        }
        return false;
    };
    int ans = *ranges::lower_bound(ranges::iota_view(1, _n / 2 + 1), 0, check) - 1;
    cout << ans * 2 << '\n';
    // int lb = 0, ub = _n / 2 + 1;
    // while (ub - lb > 1) {
    //     int mid = (lb + ub) / 2;
    //     check(mid) ? lb = mid : ub = mid;
    // }
    // cout << lb * 2 << '\n';
}