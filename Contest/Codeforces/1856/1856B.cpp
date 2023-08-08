/**
 * @file    :   1856B
 * @author  :   Tanphoon
 * @date    :   2023/08/05 22:44
 * @version :   2023/08/05 22:44
 * @link    :   https://codeforces.com/contest/1856/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;

bool solve() {
    int n;
    cin >> n;
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1)
            cnt++;
        else
            sum += x;
    }
    if (n == 1)
        return false;
    if (sum - (n - cnt) >= cnt)
        return true;
    else
        return false;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        puts(solve() ? "YES" : "NO");
    return 0;
}