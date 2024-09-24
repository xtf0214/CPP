/**
 * @file    :   H
 * @author  :   Tanphoon
 * @date    :   2024/04/23 00:33
 * @version :   2024/04/23 00:33
 * @link    :   https://codeforces.com/gym/103107/problem/H
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> res(2);
    res[0] = n / 2;
    res[1] = n;
    int ok = 1;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        cout << res[ok] << ' ' << res[ok ^ 1] << '\n';
        res[ok] -= 1;
        ok ^= 1;
    }
    cout << n << ' ' << n << '\n';
}