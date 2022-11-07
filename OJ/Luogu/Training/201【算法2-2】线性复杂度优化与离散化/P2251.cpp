// P2251 质量检测
// https://www.luogu.com.cn/problem/P2251
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int n, m;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && i - q.front() >= m) 
            q.pop_front();
        while (!q.empty() && a[q.back()] > a[i]) // 单调递增队列
            q.pop_back();
        q.push_back(i);
        if (i >= m - 1)
            cout << a[q.front()] << endl;
    }
    return 0;
}