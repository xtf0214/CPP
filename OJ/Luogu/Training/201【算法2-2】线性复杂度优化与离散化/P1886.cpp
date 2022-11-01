// P1886 滑动窗口 /【模板】单调队列
// https://www.luogu.com.cn/problem/P1886
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n + 1), ans1, ans2;
    deque<int> qmax, qmin;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        // 求最大值单调队列
        while (!qmax.empty() && i - qmax.front() >= k)
            qmax.pop_front();
        while (!qmax.empty() && a[qmax.back()] < a[i])
            qmax.pop_back();
        qmax.push_back(i);
        if (i >= k)
            ans1.push_back(a[qmax.front()]);
        // 求最小值单调队列
        while (!qmin.empty() && i - qmin.front() >= k)
            qmin.pop_front();
        while (!qmin.empty() && a[qmin.back()] > a[i])
            qmin.pop_back();
        qmin.push_back(i);
        if (i >= k)
            ans2.push_back(a[qmin.front()]);
    }
    print(ans2);
    print(ans1);
    return 0;
}