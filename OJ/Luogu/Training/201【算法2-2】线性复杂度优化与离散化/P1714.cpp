// P1714 切蛋糕
// https://www.luogu.com.cn/problem/P1714
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n, m;
vi a, sum, mins;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a = vi(n + 1), sum = vi(n + 1), mins = vi(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];

    deque<int> q;
    for (int i = 0; i <= n; i++)
    {
        while (!q.empty() && i - q.front() >= m)
            q.pop_front();
        while (!q.empty() && sum[q.back()] > sum[i]) // 单调递增队列 q.front()为最小
            q.pop_back();

        q.push_back(i);
        mins[i] = sum[q.front()]; // 保存前sum[max(0,i-m+1),i]的最小值
    }
    int ans = -INF;
    for (int i = 1; i <= n; i++)
        ans = max(ans, sum[i] - mins[i - 1]);
    cout << ans << endl;
    return 0;
}