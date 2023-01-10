// P1020 导弹拦截
// https://www.luogu.com.cn/problem/P1020
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int solve() {
    vector<int> dp; // 单调不升子序列
    for (int i = 1; i <= n; i++)
        if (dp.empty() || dp.back() >= a[i])
            dp.push_back(a[i]);
        else // 二分查找左边第一个小于a[i]的
            *upper_bound(dp.begin(), dp.end(), a[i], greater<int>()) = a[i];
    return dp.size();
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    a.push_back(0);
    while (cin >> x)
        a.push_back(x);
    n = a.size() - 1;
    cout << solve() << endl << solve1();
    return 0;
}
/*
8
4 5 3 2 6 4 3 8
 */