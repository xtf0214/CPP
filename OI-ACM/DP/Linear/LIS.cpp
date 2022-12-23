#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int solve() {
    vector<int> dp(n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    return res;
}
int solve1() {
    vector<int> dp; // 单调升子序列
    for (int i = 1; i <= n; i++)
        if (dp.empty() || dp.back() < a[i])
            dp.push_back(a[i]);
        else // 二分查找左边第一个大于等于a[i]的
            *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    return dp.size();
}
int main() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << solve();
    return 0;
}
/*
8
4 5 3 2 6 4 3 8
 */