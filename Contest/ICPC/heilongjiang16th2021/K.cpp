/**
 * @file    :   K
 * @author  :   Tanphoon
 * @date    :   2024/04/23 00:33
 * @version :   2024/04/23 00:33
 * @link    :   https://codeforces.com/gym/103107/problem/K
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    if (s < k)
        cout << "0\n";
    else
        cout << s - k + k / 2 << '\n';
    return 0;
}