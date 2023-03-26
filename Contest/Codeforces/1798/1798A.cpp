/**
 * @file    :   1798A
 * @author  :   Tanphoon
 * @date    :   2023/03/26 22:42
 * @version :   2023/03/26 22:42
 * @link    :   https://codeforces.com/contest/1798/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    // 大比大，小比小
    for (int i = 0; i < n - 1; i++)
        if (!(min(a[i], b[i]) <= min(a[n - 1], b[n - 1]) && max(a[i], b[i]) <= max(a[n - 1], b[n - 1])))
            return false;
    // 不满足就交换，交换了还不满足就是无解的
    // for (int i = 0; i < n - 1; i++) {
    //     if (a[i] > a[n - 1] || b[i] > b[n - 1])
    //         swap(a[i], b[i]);
    //     if (a[i] > a[n - 1] || b[i] > b[n - 1])
    //         return false;
    // }
    return true;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        puts(solve() ? "Yes" : "No");
    return 0;
}