/**
 * @file    :   P1439 【模板】最长公共子序列
 * @author  :   Tanphoon
 * @date    :   2023/01/10 21:19
 * @version :   2023/01/10 21:19
 * @link    :   https://www.luogu.com.cn/problem/P1439
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int solve() {
    vector<int> dp; // 单调升子序列
    for (int i = 1; i <= n; i++)
        if (dp.empty() || dp.back() < a[i])
            dp.push_back(a[i]);
        else // 二分查找左边第一个大于等于a[i]的
            *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    return dp.size();
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n + 1);
    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1, x; j <= n; j++)
        cin >> x, r[x] = j;
    for (int i = 1; i <= n; i++)
        a[i] = r[a[i]];
    cout << solve();
    return 0;
}