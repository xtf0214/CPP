// P1440 求m区间内的最小值
// https://www.luogu.com.cn/problem/P1440
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

int n, m;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vi a(n), ans;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ans.push_back(0);
    deque<int> q;
    for (int i = 0; i < n - 1; i++)
    {
        while (!q.empty() && i - q.front() >= m)
            q.pop_front();
        while (!q.empty() && a[q.back()] > a[i]) // 单调递增队列
            q.pop_back();
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";
    return 0;
}