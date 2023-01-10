/** 
 * @file    :   Codeforces Round #838 (Div. 2) A
 * @author  :   Tanphoon 
 * @date    :   2022/12/15 22:35
 * @version :   2022/12/15 22:35
 * @link    :   https://codeforces.com/contest/1762/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> num(1e6 + 1); // 通过右移操作变成偶数的次数
int solve() {
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x & 1) // 奇数
            a.push_back(num[x]);
        else // 偶数
            b.push_back(num[x]);
    }
    if (a.size() % 2 == 0)
        return 0;
    int x = INT_MAX, y = INT_MAX;
    if (!b.empty())
        y = *min_element(b.begin(), b.end());
    x = *min_element(a.begin(), a.end());
    return min(x, y);
}
void init() {
    // 打表找规律
    // int n = 500;
    // vector<pair<int, int>> a(n);
    // for (int i = 0; i < n; i++) {
    //     int cnt = 0;
    //     if (i % 2 == 0)
    //         for (int x = i; (x & 1) != 1 && x > 0; x >>= 1)
    //             cnt++;
    //     else
    //         for (int x = i; x & 1; x >>= 1)
    //             cnt++;
    //     a[i] = {cnt, i};
    //     cout << i << " " << cnt << endl;
    // }
    // // sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++)
    //     cout << a[i].second << " " << a[i].first << endl;
    for (int i = 1; (1 << i) - 1 <= 1000000; i++)
        for (int j = (1 << i) - 1; j <= 1000000; j += 1 << (i + 1))
            num[j] = i;
    for (int i = 1; (1 << i) <= 1000000; i++)
        for (int j = (1 << i); j <= 1000000; j += 1 << (i + 1))
            num[j] = i;
    // for (int i = 0; i < n; i++)
    //     cout << i << " " << a[i].first << " " << num[i] << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}